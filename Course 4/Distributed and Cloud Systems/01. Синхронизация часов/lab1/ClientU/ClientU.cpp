#include <iostream>
#include <cstring>      // Для memset
#include <sys/socket.h> // Для socket, sendto, recvfrom
#include <arpa/inet.h>  // Для inet_addr, htons
#include <unistd.h>     // Для close
#include <climits>      // Для INT_MIN и INT_MAX
#include <chrono>
#include <thread>

using namespace std;

struct SETSINCRO {
    int correction;
    // Другие параметры, если нужно
};

struct GETSINCRO {
    string cmd;
    int curvalue;
    // Другие параметры, если нужно
};

int calcAvgCorrection(int corrections[], int count) {
    int sum = 0;
    for (int i = 0; i <= count; i++) {
        sum += corrections[i];
    }
    return sum / (count + 1);
}

int main()
{
    // Установка локали
    setlocale(LC_CTYPE, "Russian");

    SETSINCRO setsincro;
    GETSINCRO getsincro;

    memset(&setsincro, 0, sizeof(setsincro));
    memset(&getsincro, 0, sizeof(getsincro));

    getsincro.cmd = "SINCRO";
    getsincro.curvalue = 0;

    // Параметры сервера
    string ipServer = "127.0.0.1";
    int Tc = 1000; // Интервал в миллисекундах
    int averageCorrection[10];

    cout << "Клиент запущен" << endl;

    // Создание UDP-сокета
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket < 0) {
        perror("Ошибка при создании сокета");
        return 1;
    }

    // Параметры сервера
    struct sockaddr_in serverParam;
    serverParam.sin_family = AF_INET;
    serverParam.sin_port = htons(2000);
    serverParam.sin_addr.s_addr = inet_addr(ipServer.c_str());

    int maxCorr = INT_MIN;
    int minCorr = INT_MAX;

    for (int count = 0; count < 10; count++) {
        int avg = 0;
        socklen_t ls = sizeof(serverParam);

        // Отправка и прием данных
        sendto(clientSocket, (char*)&getsincro, sizeof(getsincro), 0, (struct sockaddr*)&serverParam, ls);
        recvfrom(clientSocket, (char*)&setsincro, sizeof(setsincro), 0, (struct sockaddr*)&serverParam, &ls);

        if (maxCorr < setsincro.correction) {
            maxCorr = setsincro.correction;
        }

        if (minCorr > setsincro.correction) {
            minCorr = setsincro.correction;
        }

        averageCorrection[count] = setsincro.correction;
        avg = calcAvgCorrection(averageCorrection, count);

        cout << "Коррекция: " << setsincro.correction 
             << ", curvalue: " << getsincro.curvalue 
             << ", Avg: " << avg 
             << ", MinCorr: " << minCorr 
             << ", MaxCorr: " << maxCorr << "\n" << endl;

        // Обновление значения curvalue
        getsincro.curvalue += setsincro.correction + Tc;

        // Задержка между запросами
        this_thread::sleep_for(chrono::milliseconds(Tc));
    }

    // Закрытие сокета
    close(clientSocket);

    return 0;
}
