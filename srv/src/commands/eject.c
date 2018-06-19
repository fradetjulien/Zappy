#include "server.h"

void eject(server *server, int i)
{
    dprintf(server->client[i].fd, "Eject\n");
}
