FROM ubuntu:18.04

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y


EXPOSE 33333

WORKDIR /root/
RUN mkdir server
WORKDIR /root/Navruzov_221_3210/
COPY . /root/Navruzov_221_3210/


RUN qmake hallServer.pro
RUN make

ENTRYPOINT ["./hallServer"]