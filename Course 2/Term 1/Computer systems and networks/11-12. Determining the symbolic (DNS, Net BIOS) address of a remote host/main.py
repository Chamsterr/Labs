import re
import subprocess as sp


def get_DNS_by_ip(ip):
    info = sp.Popen("nslookup " + ip, stdout=sp.PIPE)
    text = info.stdout.read().decode("cp866").split("\n")[3].split("Name:")[1]
    return text[4:]


def get_ip_by_DNS(DNS):
    info = sp.Popen("nslookup " + DNS, stdout=sp.PIPE, stderr=sp.PIPE)
    text = info.stdout.read().decode("cp866")
    text = re.findall("Addresses: .*", text.replace("\r\n\t", ""))
    return text[0]


if __name__ == "__main__":
    DNS_OR_IP = input("Enter DNS or IP: ")
    if len(DNS_OR_IP.split(".")) == 4 and DNS_OR_IP[0].isdigit():
        print(f"DNS имя: {get_DNS_by_ip(DNS_OR_IP)}")
    else:
        print(f"{get_ip_by_DNS(DNS_OR_IP)}")