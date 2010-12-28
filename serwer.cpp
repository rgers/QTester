#include "serwer.h"

Serwer::Serwer()
{
    moveToThread(this);
}

void Serwer::run()
{
init();
exec();
}

void Serwer::init()
{
 serw = new QTcpServer();
 serw->listen(QHostAddress::Any,7557);
 connect(serw, SIGNAL(newConnection()), this, SLOT(obsluz_polaczenie()));
}

void Serwer::obsluz_polaczenie()
{
    QTcpSocket* soket = serw->nextPendingConnection();
    polaczenie conn(soket, polaczenia.length());
    polaczenia.append(conn);
    connect(soket, SIGNAL(readyRead()), this, SLOT(czytaj_soket()));
}

void Serwer::czytaj_soket()
{
    QTcpSocket* soket = (QTcpSocket*)QObject::sender();
    QString data;
    QDataStream strim(soket);
    char* hchar;
    uint bytesav;
    bytesav = soket->bytesAvailable();
    hchar = new char[soket->bytesAvailable()];
    strim.readBytes(hchar, bytesav);
    data = hchar;

    qDebug()<<data;
    if (data=="ACK")
    {
        int nr = znajdz_noresp_po_socketcie(soket);
        if (nr!=-1)
        {
            noresponse.removeAt(nr);
        }
    }
    else
    {
        wyslij_msg("ACK", znajdz_conn_po_socketcie(soket));

        wyslij_msg(data,znajdz_conn_po_socketcie(soket));
    }
    if(soket->bytesAvailable()>0)
    {
        czytaj_soket();
    }
}

void Serwer::wyslij_msg(QString msg, int connid)
{
    polaczenie conn = polaczenia.at(connid);
    QTcpSocket* soket = conn.getSocket();
    QDataStream strim(soket);
    char* test;
    uint huint;
    test = new char[msg.length()];
    test = (char*)msg.toAscii().constData();
    huint=msg.length();
    strim.writeBytes(test,huint);
    //delete[] test;
    noresponse.append(conn);
}

int Serwer::znajdz_conn_po_socketcie(QTcpSocket* soket)
{
    for(int a=0;a<polaczenia.length();a++)
    {
        polaczenie conn = polaczenia.at(a);
        if (conn.getSocket()==soket)
        {return a;}
    }
    return -1;
}


int Serwer::znajdz_noresp_po_socketcie(QTcpSocket* soket)
{
    for(int a=0;a<noresponse.length();a++)
    {
        polaczenie conn = polaczenia.at(a);
        if (conn.getSocket()==soket)
        {return a;}
    }
    return -1;
}
