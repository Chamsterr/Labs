import socket
import time

HOST = "0.0.0.0"
PORT = 1122
MAX_REQUESTS = 10

request_count = 0
corrections = []
server_start_time = time.time()

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket:
    server_socket.bind((HOST, PORT))
    print("Сервер запущен и ждет запросов...")

    while request_count < MAX_REQUESTS:
        try:
            data, addr = server_socket.recvfrom(1024)
            client_time = int(data.decode())
            request_count += 1

            server_time = int((time.time() - server_start_time) * 1000)

            correction = server_time - client_time
            corrections.append(correction)

            avg_correction = sum(corrections) / request_count

            print(f"IP клиента: {addr[0]}, Номер запроса: {request_count}, Correction: {correction}, Среднее correction: {avg_correction}")

            server_socket.sendto(str(correction).encode(), addr)

        except KeyboardInterrupt:
            print("\nПрерывание сервера с клавиатуры.")
            break

    if corrections:
        avg_correction = sum(corrections) / len(corrections)
        max_correction = max(corrections)
        min_correction = min(corrections)

        print("\nСервер завершил работу.")
        print(f"Средняя задержка: {avg_correction} мс")
        print(f"Максимальная задержка: {max_correction} мс")
        print(f"Минимальная задержка: {min_correction} мс")
    else:
        print("\nНе было получено ни одного запроса.")
