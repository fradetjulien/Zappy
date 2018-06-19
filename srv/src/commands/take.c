#include "server.h"

void take(server *server, int i)
{
    dprintf(server->client[i].fd, "Take\n");
}
