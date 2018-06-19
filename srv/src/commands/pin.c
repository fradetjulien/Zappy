#include "server.h"

void pin(server *server, int i)
{
    dprintf(server->client[i].fd, "Pin\n");
}
