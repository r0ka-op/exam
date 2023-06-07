#include "mytcpserver.h"
const int port = 33333;


MyTcpServer::MyTcpServer() // Конструктор
{
    if(this->listen(QHostAddress::Any, port)){
        server_status=1;
        qDebug() << "\r\nserver is started in port #" << port;
        qDebug() << "putty -telnet localhost" << port << "\r\n";
    } else {
        qDebug() << "server is not started";
    }
    server_status=0;
}



void MyTcpServer::incomingConnection(qintptr socketDescriptor){
        oneSocket = new QTcpSocket;
        oneSocket->setSocketDescriptor(socketDescriptor);
        oneSocket -> write("I am start!\r\n");

        qDebug() << "Connect client: " << socketDescriptor;
        connect(oneSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
        connect(oneSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
        Sockets.push_back(oneSocket);
}

void MyTcpServer::slotServerRead(){
    oneSocket = (QTcpSocket*)sender();

    QString res = oneSocket->readAll();

    if (res == "disconnect")
        {
            oneSocket -> write("\r\nU r Disconnected\r\nBye Bye\r\n\r\n");
            slotClientDisconnected();
        }
    else
        oneSocket -> write(parsing(res.toUtf8()).toUtf8());
}


void MyTcpServer::slotClientDisconnected(){
    oneSocket->disconnect();
}
