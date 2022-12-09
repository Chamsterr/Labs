def check_adress(ip):
    ip = [x if 0 <= x <= 255 else None for x in ip]
    return ip if None not in ip else None


def check_mask(mask):
    test = "".join(map(bin, mask)).replace("0b", "")
    if "01" in test:
        return None
    return mask


def main():
    ip = check_adress(list(map(int, input("Введите ip adress: ").split("."))))
    mask = check_mask(list(map(int, input("Введите маску: ").split("."))))

    if mask and ip:
        networkID = [ip[i] & mask[i] for i in range(len(mask))]
        hostID = [ip[i] & ~mask[i] for i in range(len(mask))]
        broadcast = [ip[i] | mask[i] ^ 255 for i in range(len(mask))]
        print(
            f"networkID - {networkID}\n"
            f"hostID - {hostID} \n"
            f"broadcast - {broadcast}"
        )
        return 0
    elif mask or ip:
        print("Неверная маска" if not mask else "Неверный ip адрес")
    else:
        print("Неверная маска и неверный ip адрес")


if __name__ == "__main__":
    main()
