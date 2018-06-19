#include "server.h"

void mct(server *server, int i)
{
    dprintf(server->client[i].fd, "Mct\n");
}
