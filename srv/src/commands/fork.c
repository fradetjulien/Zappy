#include "server.h"

void _fork(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Fork\n");
}
