import socket
import struct
import time
import threading
import ntplib
from datetime import datetime

def get_local_unix_time():
    return int(time.time() * 1000)


def sync_global_unix_time(ex_time):
    client = ntplib.NTPClient()
    ntp_server = "pool.ntp.org"

    
    while True:
        try:
            response = client.request(ntp_server, version=3)
            ntp_time = int(response.tx_time * 1000)
            local_time = get_local_unix_time()
            
            transmission_time = response.delay * 1000
            tms = int(ntp_time + (transmission_time / 2))

            with ex_time['lock']:
                ex_time['mTime'] = tms

            print(f"Синхронизация NTP с глобальным временем")
            print(f"Локальное UNIX время: {local_time}, Глобальное NTP: {tms}")
            if tms > local_time:
                print(f"Глобальное время больше на {tms - local_time} мс")
            else:
                print(f"Локальное время больше на {local_time - tms} мс")
            print()

        except Exception as e:
            print(f"Ошибка при синхронизации с NTP сервером: {e}")
        
        time.sleep(10)


def server_loop(ex_time):
    """Основной цикл работы сервера для обработки запросов."""
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('192.168.171.51', 1234))
    print("Сервер запущен и ожидает запросы.")

    while True:
        try:
            data, client_address = server_socket.recvfrom(1024)
            client_time = struct.unpack('!Q', data)[0]

            with ex_time['lock']:
                current_global_time = ex_time['mTime']
            
            local_delta = get_local_unix_time() - current_global_time
            correction = int(current_global_time + local_delta - client_time)

            response_data = struct.pack('!q', correction)
            server_socket.sendto(response_data, client_address)

            print(f"Обработка запроса клиента. Время клиента: {client_time}, Коррекция: {correction}")

        except Exception as e:
            print(f"Ошибка при обработке запроса: {e}")


def main():
    ex_time = {'mTime': 0, 'lock': threading.Lock()}

    sync_thread = threading.Thread(target=sync_global_unix_time, args=(ex_time,))
    sync_thread.daemon = True
    sync_thread.start()

    try:
        server_loop(ex_time)
    except KeyboardInterrupt:
        print("Остановка сервера...")

if __name__ == "__main__":
    main()
