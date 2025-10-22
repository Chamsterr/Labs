import socket
import time

SERVER_HOST = '192.168.100.7'
SERVER_PORT = 1122

Tc = 1000
num_requests = 20

client_time = 0

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client_socket:
    for request_num in range(1, num_requests + 1):
        client_socket.sendto(str(client_time).encode(), (SERVER_HOST, SERVER_PORT))

        data, _ = client_socket.recvfrom(1024)
        correction = int(data.decode())

        client_time += Tc + correction

        print(f"Запрос: {request_num}, Текущее время клиента: {client_time}, Correction: {correction}")

        time.sleep(Tc / 1000.0)