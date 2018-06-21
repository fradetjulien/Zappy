#include "server.h"

void sst(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Sst\n");
}
