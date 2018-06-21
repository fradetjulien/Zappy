#include "server.h"

void eject(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Eject\n");
}
