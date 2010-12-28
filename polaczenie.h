#ifndef POLACZENIE_H
#define POLACZENIE_H

#include <QTcpSocket>

class polaczenie
{
public:
    polaczenie(QTcpSocket* sock, int idset);
    void setSocket(QTcpSocket* sock);
    QTcpSocket* getSocket();
    void setID(int idset);
    int getID();
    int resp_time;
    QString lastmsg;
    int lastsend;

private:
    QTcpSocket* soket;
    int id;

};

#endif // POLACZENIE_H
