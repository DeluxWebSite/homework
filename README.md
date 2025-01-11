### Домашнее задание к занятию 1 «Disaster recovery и Keepalived» - Мельник С В
### Задание 1
* Дана схема для Cisco Packet Tracer, рассматриваемая в лекции.
* На данной схеме уже настроено отслеживание интерфейсов маршрутизаторов Gi0/1 (для нулевой группы)
* Необходимо аналогично настроить отслеживание состояния интерфейсов Gi0/0 (для первой группы).
* Для проверки корректности настройки, разорвите один из кабелей между одним из маршрутизаторов и Switch0 и запустите ping между PC0 и Server0.
* На проверку отправьте получившуюся схему в формате pkt и скриншот, где виден процесс настройки маршрутизатора.
---------------------------------------------------------
#### * *
[файл pkt](https://github.com/DeluxWebSite/homework/blob/main/hsrp_advanced-2.pkt)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Снимок%20экрана%202025-01-11%20в%2011.10.45.png)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Снимок%20экрана%202025-01-11%20в%2011.17.01.png)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Снимок%20экрана%202025-01-11%20в%2011.17.43.png)
---------------------------------------------------------
### Задание 2
* Запустите две виртуальные машины Linux, установите и настройте сервис Keepalived как в лекции, используя пример конфигурационного файла.
* Настройте любой веб-сервер (например, nginx или simple python server) на двух виртуальных машинах
* Напишите Bash-скрипт, который будет проверять доступность порта данного веб-сервера и существование файла index.html в root-директории данного веб-сервера.
* Настройте Keepalived так, чтобы он запускал данный скрипт каждые 3 секунды и переносил виртуальный IP на другой сервер, если bash-скрипт завершался с кодом, отличным от нуля (то есть порт веб-сервера был недоступен или отсутствовал index.html). Используйте для этого секцию vrrp_script
* На проверку отправьте получившейся bash-скрипт и конфигурационный файл keepalived, а также скриншот с демонстрацией переезда плавающего ip на другой сервер в случае недоступности порта или файла index.html
--------------------------------------------------------
![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-10%2014-19-33.png)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-10%2014-22-31.png)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-10%2014-25-23.png)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-10%2014-25-59.png)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-10%2014-43-16.png)
![alt](https://github.com/DeluxWebSite/homework/blob/main/Screenshot%20from%202025-01-10%2014-53-33.png)
