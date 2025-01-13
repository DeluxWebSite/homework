### Домашнее задание к занятию 2 «Кластеризация и балансировка нагрузки» - Мельник С В
### Задание 1
* Запустите два simple python сервера на своей виртуальной машине на разных портах
* Установите и настройте HAProxy, воспользуйтесь материалами к лекции по ссылке
* Настройте балансировку Round-robin на 4 уровне.
* На проверку направьте конфигурационный файл haproxy, скриншоты, где видно перенаправление запросов на разные серверы при обращении к HAProxy.
---------------------------------------------------------
![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-13%2010-52-35.png)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-13%2010-53-51.png)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-13%2010-54-56.png)

---------------------------------------------------------
### Задание 2
* Запустите три simple python сервера на своей виртуальной машине на разных портах
* Настройте балансировку Weighted Round Robin на 7 уровне, чтобы первый сервер имел вес 2, второй - 3, а третий - 4
* HAproxy должен балансировать только тот http-трафик, который адресован домену example.local
* На проверку направьте конфигурационный файл haproxy, скриншоты, где видно перенаправление запросов на разные серверы при обращении к HAProxy c использованием домена example.local и без него.

--------------------------------------------------------

![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-13%2010-56-05.png)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-13%2010-57-34.png)


#### [файл nginx.conf](https://github.com/DeluxWebSite/homework/blob/main/nginx.conf)

#### [файл upstream.inc](https://github.com/DeluxWebSite/homework/blob/main/upstream.inc)
