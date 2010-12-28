#include "klient.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <iostream>
void klient::run()
{

    QHostAddress adres;
    adres.setAddress("127.0.0.1");
    soket = new QTcpSocket();
    connect(soket, SIGNAL(connected()), this, SLOT(polaczony()));
    connect(soket, SIGNAL(readyRead()), this, SLOT(czytaj_soket()));
    soket->connectToHost(adres,7557);
    exec();
}

void klient::polaczony()
{
    wyslij("To jest test");
}

void klient::czytaj_soket()
{
    QTcpSocket* soket = (QTcpSocket*)QObject::sender();
    QString data;
    char* test;
    test=new char[soket->bytesAvailable()];
    QDataStream strim(soket);
    qDebug()<<soket->bytesAvailable();
    uint testuint = soket->bytesAvailable();

    strim.readBytes(test,testuint);
    data=test;
    qDebug()<<data;
    if (data!="ACK")
    {
    wyslij("ACK");
    emit newMsg(&data);
    }
    qDebug()<<soket->bytesAvailable();
    if (soket->bytesAvailable()>0)
    {czytaj_soket();}
}

void klient::wyslij(QString wiadomosc)

{
    QDataStream strim(soket);
    char* hchar;
    hchar = new char[wiadomosc.length()];
    hchar = (char*)wiadomosc.toAscii().constData();
    uint huint;
    huint = wiadomosc.length();
    strim.writeBytes((char*)wiadomosc.toAscii().constData(), huint);
}
