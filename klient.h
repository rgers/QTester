#ifndef KLIENT_H
#define KLIENT_H

#include <QThread>
#include <QTcpSocket>

class klient : public QThread
{
    Q_OBJECT
public:
    void run();
    void wyslij(QString wiadomosc);

signals:
    void newMsg(QString* msg);

public slots:
    void polaczony();
    void czytaj_soket();

private:
    QTcpSocket* soket;
};

#endif // KLIENT_H
