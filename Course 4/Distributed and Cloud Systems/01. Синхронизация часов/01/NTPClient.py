import socket
import time
import struct
import sys


def get_local_unix_time():
    """Получаем текущее время в формате Unix в миллисекундах."""
    return int(time.time() * 1000)

def main():
    time.sleep(0.1)
    
    IP = "192.168.100.7"
    PORT = 1234
    TC = 1000

    maxcorr = 0
    mincorr = sys.maxsize
    mcorr = 0
    mCcOs = 0

    client_time = 0
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        
        server_address = (IP, PORT)
        
        initial_data = struct.pack('!Q', 0)
        sock.sendto(initial_data, server_address)
        
        data, _ = sock.recvfrom(1024)
        ss_corr_time = struct.unpack('!Q', data)[0]
        client_time = ss_corr_time
        print(f"Начальная коррекция: {ss_corr_time}\n")

        for i in range(10):
            time.sleep(TC / 1000)
            
            client_time += TC
            send_data = struct.pack('!Q', client_time)
            sock.sendto(send_data, server_address)
            
            data, _ = sock.recvfrom(1024)
            ss_corr_time = struct.unpack('!Q', data)[0]

            local_unix_time = get_local_unix_time()

            client_time += ss_corr_time
            mcorr += ss_corr_time
            mCcOs += client_time - local_unix_time

            maxcorr = max(maxcorr, ss_corr_time)
            mincorr = min(mincorr, ss_corr_time)

            print(f"Время клиента: {client_time}, Локальное время: {local_unix_time}, Коррекция: {ss_corr_time}")
            
            if client_time > local_unix_time:
                print(f"Время клиента больше на {client_time - local_unix_time} миллисекунд.")
            else:
                print(f"Локальное время больше на {local_unix_time - client_time} миллисекунд.")
            print()

        print(f"Средняя коррекция: {mcorr / 10.0}")
        print(f"Средняя разница времени (Cc - Ostime): {mCcOs / 10.0}")
        print(f"Максимальная коррекция: {maxcorr}")
        print(f"Минимальная коррекция: {mincorr}\n")

    except Exception as e:
        print(f"Ошибка: {e}")
    
    finally:
        sock.close()

if __name__ == "__main__":
    main()
