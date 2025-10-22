#include <iostream>
#include <cstring>      // Для memset
#include <sys/socket.h> // Для socket, sendto, recvfrom
#include <arpa/inet.h>  // Для inet_ntoa, htons, INADDR_ANY
#include <unistd.h>     // Для close
#include <ctime>        // Для clock()
#include <clocale>      // Для setlocale

using namespace std;

// Структуры, которые были в вашем заголовочном файле
struct SETSINCRO {
    int correction;
    string cmd;
};

struct GETSINCRO {
    int curvalue;
    string cmd;
};

// Функция для вывода текущего времени (эмулирует PrintCurrentTime)
void PrintCurrentTime() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    cout << "Текущее время: " << asctime(localTime);
}

int main() {
    // Установка локали
    setlocale(LC_ALL, "Russian");

    // Инициализация структур
    SETSINCRO setsincro;
    GETSINCRO getsincro;

    memset(&setsincro, 0, sizeof(setsincro));
    memset(&getsincro, 0, sizeof(getsincro));

    setsincro.cmd = "SINCRO";
    setsincro.correction = 0;

    clock_t timer;
    int averageCorrection[10];

    cout << "Сервер запущен" << endl;

    // Создание UDP-сокета
    int servSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (servSocket < 0) {
        perror("Ошибка при создании сокета");
        return 1;
    }

    // Параметры сервера
    struct sockaddr_in serverParam;
    serverParam.sin_family = AF_INET;
    serverParam.sin_port = htons(2000);
    serverParam.sin_addr.s_addr = INADDR_ANY;

    // Привязка сокета к адресу
    if (bind(servSocket, (struct sockaddr*)&serverParam, sizeof(serverParam)) < 0) {
        perror("Ошибка при привязке сокета");
        close(servSocket);
        return 1;
    }

    int count = 0;
    while (true) {
        struct sockaddr_in clientParam;
        socklen_t lc = sizeof(clientParam);
        int avg = 0;

        // Получение данных от клиента
        recvfrom(servSocket, (char*)&getsincro, sizeof(getsincro), 0, (struct sockaddr*)&clientParam, &lc);

        timer = clock();
        cout << "Сервер: " << timer << endl;

        // Рассчет коррекции
        setsincro.correction = timer - getsincro.curvalue;

        // Отправка данных клиенту
        sendto(servSocket, (char*)&setsincro, sizeof(setsincro), 0, (struct sockaddr*)&clientParam, lc);

        // Печать текущего времени и данных клиента
        PrintCurrentTime();
        cout << inet_ntoa(clientParam.sin_addr) 
             << " Коррекция: " << setsincro.correction 
             << ", у клиента(curvalue): " << getsincro.curvalue << "\n" << endl;

        count++;
    }

    // Закрытие сокета
    close(servSocket);

    return 0;
}
