#ifndef SERWER_H
#define SERWER_H

#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include "polaczenie.h"

class Serwer : public QThread
{
    Q_OBJECT
public:
    Serwer();
    void run();
    void wyslij_msg(QString msg, int connid);
    void init();

signals:

public slots:
    void obsluz_polaczenie();
    void czytaj_soket();

private:
    int znajdz_noresp_po_socketcie(QTcpSocket* soket);
    int znajdz_conn_po_socketcie(QTcpSocket* soket);
    QTcpServer* serw;
    QList<polaczenie> polaczenia;
    QList<polaczenie> noresponse;
};

#endif // SERWER_H
