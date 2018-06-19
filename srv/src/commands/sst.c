#include "server.h"

void sst(server *server, int i)
{
    dprintf(server->client[i].fd, "Sst\n");
}
