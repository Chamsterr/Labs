import os


def get_mac(ip):
    mac = os.popen("arp -a " + ip).read()
    if mac not in f"ARP: bad argument: {ip}":
        print(f"{ip}: {mac.split('   ')[-3]}")


def get_ip(mac):
    ip = os.popen("arp -a").read().split("   ")
    index = ip.index(" " + mac)
    ip = ip[index - 2].replace("\n", "")
    print(f"{mac}: {ip}")


if __name__ == "__main__":
    print(os.popen("arp -a ").read())
    # ip = input("IP adress: ")
    # get_mac(ip)
    mac = input("MAC adress: ")
    get_ip(mac)
