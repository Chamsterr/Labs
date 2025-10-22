#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ctime>
#include <pthread.h>
#include <netinet/in.h>
#include <netdb.h>
#include <chrono>

using namespace std;

// Структуры для передачи данных (можно изменить по необходимости)
struct NTP_packet {
    uint8_t head[4];
    uint32_t OriginateTimestamp[2];
    uint32_t TransmitTimestamp[2];
};

struct GETSINCHRO {
    uint64_t mTime;
};

struct SETSINCHRO {
    int64_t corrTime;
};

// Функция для получения локального времени Unix
uint64_t GetLocalUnixTime() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
}

pthread_mutex_t mutexServerTime = PTHREAD_MUTEX_INITIALIZER;
clock_t lastSync = 0;

void* SyncGlobalUnixTime(void* lpar) {
    int sockfd;
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("178.124.134.106"); // NTP сервер
    server_addr.sin_port = htons(123);

 	int64_t d = 613608LL * 3600LL; // 613608 * 3600 сек NTP - UNIX
    NTP_packet out_buf, in_buf;

    while (true) {
        memset(&out_buf, 0, sizeof(out_buf));
        memset(&in_buf, 0, sizeof(in_buf));

        out_buf.head[0] = 0x1B;

        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            cerr << "Ошибка создания сокета: " << strerror(errno) << endl;
            return nullptr;
        }

        struct timeval timeout = {20, 0}; // 20 секунд
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

        socklen_t len = sizeof(server_addr);

        auto qtime = clock();
        if (sendto(sockfd, &out_buf, sizeof(out_buf), 0, (struct sockaddr*)&server_addr, len) < 0) {
            cerr << "Ошибка отправки данных: " << strerror(errno) << endl;
            close(sockfd);
            return nullptr;
        }

        if (recvfrom(sockfd, &in_buf, sizeof(in_buf), 0, (struct sockaddr*)&server_addr, &len) < 0) {
            cerr << "Ошибка получения данных: " << strerror(errno) << endl;
            close(sockfd);
            return nullptr;
        }

        clock_t transmissionTime = clock() - qtime;
        uint64_t localUnixTime = GetLocalUnixTime();

        in_buf.TransmitTimestamp[0] = ntohl(in_buf.TransmitTimestamp[0]) - d;
        in_buf.OriginateTimestamp[0] = ntohl(in_buf.OriginateTimestamp[0]) - d;
        in_buf.TransmitTimestamp[1] = ntohl(in_buf.TransmitTimestamp[1]);
        in_buf.OriginateTimestamp[1] = ntohl(in_buf.OriginateTimestamp[1]);

        uint64_t tms = ((uint64_t)((1000.0 * ((double)(in_buf.TransmitTimestamp[1]) / (double)0xffffffff)) + (uint64_t)in_buf.TransmitTimestamp[0] * 1000));
        uint64_t oms = ((uint64_t)((1000.0 * ((double)(in_buf.OriginateTimestamp[1]) / (double)0xffffffff)) + (uint64_t)in_buf.OriginateTimestamp[0] * 1000));

        uint64_t transmissionCorrection = (transmissionTime - (tms - oms)) / 2;
        tms = tms + transmissionCorrection;

        GETSINCHRO* t = (GETSINCHRO*)lpar;
        pthread_mutex_lock(&mutexServerTime);
        lastSync = clock();
        t->mTime = tms;
        pthread_mutex_unlock(&mutexServerTime);

        cout << "Синхронизация NTP с глобальным временем" << endl;
        cout << "Локальное UNIX время: " << localUnixTime << " Глобальное NTP: " << tms << endl;

        if (tms > localUnixTime) {
            cout << "Глобальное время больше на " << tms - localUnixTime << " мс" << endl;
        } else {
            cout << "Локальное время больше на " << localUnixTime - tms << " мс" << endl;
        }
        cout << endl;

        close(sockfd);
        sleep(10);
    }
    return nullptr;
}

int main() {
    cout << "NTP сервер запущен" << endl;

    pthread_t syncThread;
    GETSINCHRO ExTime;

    pthread_create(&syncThread, nullptr, SyncGlobalUnixTime, &ExTime);

    try {
        int serverSocket;
        struct sockaddr_in server_addr;

        serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
        if (serverSocket < 0)
            throw runtime_error("Ошибка создания сокета: " + string(strerror(errno)));

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2000);
        server_addr.sin_addr.s_addr = INADDR_ANY;

        if (bind(serverSocket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
            throw runtime_error("Ошибка биндинга: " + string(strerror(errno)));

        while (true) {
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);

            GETSINCHRO gs;
            if (recvfrom(serverSocket, &gs, sizeof(gs), 0, (struct sockaddr*)&client_addr, &client_len) < 0)
                throw runtime_error("Ошибка получения данных: " + string(strerror(errno)));

            SETSINCHRO ss;

            pthread_mutex_lock(&mutexServerTime);
            int delta = clock() - lastSync;
            ss.corrTime = ExTime.mTime + delta - gs.mTime;
            pthread_mutex_unlock(&mutexServerTime);

            sendto(serverSocket, &ss, sizeof(ss), 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
        }

        close(serverSocket);
    } catch (const std::exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    pthread_join(syncThread, nullptr);
    pthread_mutex_destroy(&mutexServerTime);
    return 0;
}
