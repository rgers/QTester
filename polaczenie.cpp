#include "polaczenie.h"

polaczenie::polaczenie(QTcpSocket* sock, int idset)
{
    id = idset;
    soket = sock;
}

int polaczenie::getID()
{
    return id;
}

QTcpSocket* polaczenie::getSocket()
{
    return soket;
}

void polaczenie::setID(int idset)
{
    id = idset;
}

void polaczenie::setSocket(QTcpSocket *sock)
{
    soket = sock;
}
