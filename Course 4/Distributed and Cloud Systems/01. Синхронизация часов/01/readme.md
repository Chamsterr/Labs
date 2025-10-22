# 1 Лаба 

1. Сетапим виртуалку
2. Получаем айпишник и конектимся через putty
````
vm-admin@server:~$ ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host
       valid_lft forever preferred_lft forever
2: enp0s3: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
    link/ether 08:00:27:58:63:5e brd ff:ff:ff:ff:ff:ff
    inet 192.168.100.6/24 metric 100 brd 192.168.100.255 scope global dynamic enp0s3
       valid_lft 86084sec preferred_lft 86084sec
    inet6 fe80::a00:27ff:fe58:635e/64 scope link
       valid_lft forever preferred_lft forever
````

3. Получаем ip на винде чтобы заканектиться на виртуалке
```
Wireless LAN adapter Беспроводная сеть:

   Connection-specific DNS Suffix  . :
   IPv4 Address. . . . . . . . . . . : 192.168.100.7
   Subnet Mask . . . . . . . . . . . : 255.255.255.0
   Default Gateway . . . . . . . . . : 192.168.100.1
```
4. Переносим клиент на виртуалку + настройка (меняем на свой айпи сервера на клиенте)
5. Стартуем сервер для первого задания на локалке и клиент на виртуалке
6. И меняем TC по условию на 1000 3000 и тд
6. Так же и со вторым заданием тока там уже нельзя 0.0.0.0 пробросить на сервере хз почему



# Сдача
Норм сдал Уласевичу, он меня не трогал потому что на пайтоне. просто попрасил все запустить и по справишал про айпишник в ntp server (у меня там хостнейм). в конце спросил что такое NTP