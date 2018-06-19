#include "server.h"

void bct(server *server, int i)
{
    dprintf(server->client[i].fd, "Bct\n");
}
