### Домашнее задание к занятию 4 «Оркестрация группой Docker контейнеров на примере Docker Compose» -- Мельник С.В.

#### Задача 1

Сценарий выполнения задачи:

- Установите docker и docker compose plugin на свою linux рабочую станцию или ВМ.
- Если dockerhub недоступен создайте файл /etc/docker/daemon.json с содержимым: {"registry-mirrors": ["https://mirror.gcr.io", "https://daocloud.io", "https://c.163.com/", "https://registry.docker-cn.com"]}
- Зарегистрируйтесь и создайте публичный репозиторий с именем "custom-nginx" на https://hub.docker.com (ТОЛЬКО ЕСЛИ У ВАС ЕСТЬ ДОСТУП);
- скачайте образ nginx:1.21.1;
- Создайте Dockerfile и реализуйте в нем замену дефолтной индекс-страницы(/usr/share/nginx/html/index.html), на файл index.html с содержимым:

\*<html>

<head>
Hey, Netology
</head>
<body>
<h1>I will be DevOps Engineer!</h1>
</body>
</html>*
- Соберите и отправьте созданный образ в свой dockerhub-репозитории c tag 1.0.0 (ТОЛЬКО ЕСЛИ ЕСТЬ ДОСТУП).
- Предоставьте ответ в виде ссылки на https://hub.docker.com/<username_repo>/custom-nginx/general .

---

- Установил Docker:

- sudo apt-get update;
- sudo apt install git curl;
- curl -fsSL get .docker.com -o get -docker.sh;
- chmod +x get-docker.sh;
- ./get-docker.sh
- docker pull hello-world;
- docker run hello-world

- Установил Docker compose:

- curl -L https://github.com/docker/compose/releases/download/v2.5.1/docker compose-uname -s-uname -m -o /usr/bin/docker-compose;
- chmod +x /usr/bin/docker-compose
- docker-compose version

- Зарегистрировался на https://hub.docker.com
- Скачал образ nginx:1.21.1
- docker pull nginx:1.21.1
- Создал Docerfile с заменой дефолтной индекс-страницы согласно задания FROM nginx:1.21.1 COPY ./index.html /usr/share/nginx/html/index.html EXPOSE 80
- Собрал докер образ: dokcer build -t custom-nginx:1.0.0 .
- Собрал и отправил созданный образ в свой dockerhub-репозиторий docker tag custom-nginx:1.0.0 sergeymeljnick78/custom-nginx:1.0.0 docker push sergeymeljnick78/custom-nginx:1.0.0
  Ссылка в dockerhub-репозиторий:[ https://hub.docker.com/repository/docker/sergeymeljnick78/custom-nginx/general](https://hub.docker.com/repository/docker/sergeymeljnick78/custom-nginx/general)

---

#### Задача 2

- Запустите ваш образ custom-nginx:1.0.0 командой docker run в соответвии с требованиями:
  имя контейнера "ФИО-custom-nginx-t2"
- контейнер работает в фоне
- контейнер опубликован на порту хост системы 127.0.0.1:8080
- Не удаляя, переименуйте контейнер в "custom-nginx-t2"
- Выполните команду date +"%d-%m-%Y %T.%N %Z" ; sleep 0.150 ; docker ps ; ss -tlpn | grep 127.0.0.1:8080 ; docker logs custom-nginx-t2 -n1 ; docker exec -it custom-nginx-t2 base64 /usr/share/nginx/html/index.html
- Убедитесь с помощью curl или веб браузера, что индекс-страница доступна.
  В качестве ответа приложите скриншоты консоли, где видно все введенные команды и их вывод.

---

- Запустил созданный образ docker run -it --rm -d -p 8080:80 --name msv-custom-nginx-t2 custom-nginx:1.0.0
- Переименовываю контейнер docker rename msv-custom-nginx-t2 custom-nginx-t2
- Выполняю команду date +"%d-%m-%Y %T.%N %Z" ; sleep 0.150 ; docker ps ; ss -tlpn | grep 127.0.0.1:8080 ; docker logs custom-nginx-t2 -n1 ; docker exec -it custom-nginx-t2 base64 /usr/share/nginx/html/index.html

  ![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-11-46-59.png)

---

#### Задача 3

1. Воспользуйтесь docker help или google, чтобы узнать как подключиться к стандартному потоку ввода/вывода/ошибок 2. контейнера "custom-nginx-t2".
2. Подключитесь к контейнеру и нажмите комбинацию Ctrl-C.
3. Выполните docker ps -a и объясните своими словами почему контейнер остановился.
4. Перезапустите контейнер
5. Зайдите в интерактивный терминал контейнера "custom-nginx-t2" с оболочкой bash.
6. Установите любимый текстовый редактор(vim, nano итд) с помощью apt-get.
7. Отредактируйте файл "/etc/nginx/conf.d/default.conf", заменив порт "listen 80" на "listen 81".
8. Запомните(!) и выполните команду nginx -s reload, а затем внутри контейнера curl http://127.0.0.1:80 ; curl http://127.0.0.1:81.
9. Выйдите из контейнера, набрав в консоли exit или Ctrl-D.
10. Проверьте вывод команд: ss -tlpn | grep 127.0.0.1:8080 , docker port custom-nginx-t2, curl http://127.0.0.1:8080. Кратко объясните суть возникшей проблемы.
11. - Это дополнительное, необязательное задание. Попробуйте самостоятельно исправить конфигурацию контейнера, используя доступные источники в интернете. Не изменяйте конфигурацию nginx и не удаляйте контейнер. Останавливать контейнер можно. пример источника
12. Удалите запущенный контейнер "custom-nginx-t2", не останавливая его.(воспользуйтесь --help или google)
    В качестве ответа приложите скриншоты консоли, где видно все введенные команды и их вывод.

---

- Подключаемся к контейнеру через docker attach

  ![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-11-55-59.png)

- Нажимаю Ctrl-C и выполняю команду docker ps -a Завершилась работа контейнера, т.к. Ctrl-C это сигнал завершения процесса, для фоновой работы процесса необходимо установить ключ -d и тогда контейнер продолжит работу, а мы отключимся от него.

  ![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-11-56-37.png)

- Перезапускаем контейнер и заходим в интерактивный режим контейнера docker exec -it custom-nginx-t2 bash

  ![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-12-23-29.png)

- Устанавливаю текстовый редактор nano apt install nano

  ![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-12-23-29.png)

- Отредактировал файл "/etc/nginx/conf.d/default.conf", заменив порт "listen 80" на "listen 81"

  ![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-12-27-47.png)

- Рестарт сервера и проверка доступности портов 80 порт закрылся и открылся 81

  ![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-12-29-32.png)

- Вышел из контейнера exit

- Обращение на порт 8080 выдает ошибку, т.к. 80 порт нашего контейнера который прокидывался на порт 8080 мы поменяли 81

![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-12-30-41.png)

- Удаляем контейнер без остатка с ключем -f docker rm custom-nginx-t2 -f custom-nginx-t2

![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-12-32-23.png)

---

#### Задача 4

- Запустите первый контейнер из образа centos c любым тегом в фоновом режиме, подключив папку текущий рабочий каталог $(pwd) на хостовой машине в /data контейнера, используя ключ -v.
- Запустите второй контейнер из образа debian в фоновом режиме, подключив текущий рабочий каталог $(pwd) в /data контейнера.
- Подключитесь к первому контейнеру с помощью docker exec и создайте текстовый файл любого содержания в /data.
- Добавьте ещё один файл в текущий каталог $(pwd) на хостовой машине.
- Подключитесь во второй контейнер и отобразите листинг и содержание файлов в /data контейнера.
  В качестве ответа приложите скриншоты консоли, где видно все введенные команды и их вывод.

---

- Скачал образ centos:7 docker pull centos:7
- Скачал образ debian docker pull debian
- Запустил centos и пробросил нашу текущую директорию внутрь контейнера в каталог data

- Запустил debian и пробросил нашу текущую директорию внутрь контейнера в каталог data

- Подключился к контейнеру centos и в каталоге /data создал файл file1

- Создал файл file2 на хостовой машине в текущей директории

- Подключился к контейнеру debian и вывел файлы содержащиеся в директории /data

![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-14-35-14.png)
![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-14-37-29.png)
![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-14-39-10.png)

---

#### Задача 5

1. Создайте отдельную директорию(например /tmp/netology/docker/task5) и 2 файла внутри него. "compose.yaml" с содержимым:
   version: "3"
   services:
   portainer:
   network_mode: host
   image: portainer/portainer-ce:latest
   volumes: - /var/run/docker.sock:/var/run/docker.sock
   "docker-compose.yaml" с содержимым:

version: "3"
services:
registry:
image: registry:2

    ports:
    - "5000:5000"

И выполните команду "docker compose up -d". Какой из файлов был запущен и почему? (подсказка: https://docs.docker.com/compose/compose-application-model/#the-compose-file )

2. Отредактируйте файл compose.yaml так, чтобы были запущенны оба файла. (подсказка: https://docs.docker.com/compose/compose-file/14-include/)

3. Выполните в консоли вашей хостовой ОС необходимые команды чтобы залить образ custom-nginx как custom-nginx:latest в запущенное вами, локальное registry. Дополнительная документация: https://distribution.github.io/distribution/about/deploying/

4. Откройте страницу "https://127.0.0.1:9000" и произведите начальную настройку portainer.(логин и пароль адмнистратора)

5. Откройте страницу "http://127.0.0.1:9000/#!/home", выберите ваше local окружение. Перейдите на вкладку "stacks" и в "web editor" задеплойте следующий компоуз:

version: '3'

services:
nginx:
image: 127.0.0.1:5000/custom-nginx
ports: - "9090:80" 6. Перейдите на страницу "http://127.0.0.1:9000/#!/2/docker/containers", выберите контейнер с nginx и нажмите на кнопку "inspect". В представлении <> Tree разверните поле "Config" и сделайте скриншот от поля "AppArmorProfile" до "Driver".

7. Удалите любой из манифестов компоуза(например compose.yaml). Выполните команду "docker compose up -d". Прочитайте warning, объясните суть предупреждения и выполните предложенное действие. Погасите compose-проект ОДНОЙ(обязательно!!) командой.

В качестве ответа приложите скриншоты консоли, где видно все введенные команды и их вывод, файл compose.yaml , скриншот portainer c задеплоенным компоузом.

---

1. - Создал 2 файла с содержимым из задания

- Выполнил команду docker compose up -d
- Docker compose в связи с наличием нескольких файлов конфигураций, выбирает первый файл который он находит согласно внутреннему порядку приоритетов. В данном случае это файл compose.yaml

![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-14-58-31.png)

2. version: "3"
   include:

- docker-compose.yaml
  services:
  portainer:
  image: portainer/portainer-ce:latest
  network_mode: host
  ports: - "9000:9000"
  volumes: - /var/run/docker.sock:/var/run/docker.sock

![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-15-00-57.png)

3.

4. ![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-15-54-20.png)

5. ![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-15-59-25.png)

![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-16-07-11.png)

6. ![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-16-10-45.png)

7. Удалил файл compose.yaml и запустим команду docker compose up -d

![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-16-15-11.png)

Предложено запустить команду с флагом --remove-orphans для очистки сиротского контейнера task5-portainer-1 Выполнил предложенные дейстрия

![alt text](https://github.com/DeluxWebSite/homework/blob/main/Снимок-экрана-от-2025-06-16-16-17-01.png)

Погасил проект docker compose down
