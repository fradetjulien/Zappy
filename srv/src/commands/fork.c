#include "server.h"

void _fork(server *server, int i)
{
    dprintf(server->client[i].fd, "Fork\n");
}
