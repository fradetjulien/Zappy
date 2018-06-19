#include "server.h"

void incantation(server *server, int i)
{
    dprintf(server->client[i].fd, "Incantation\n");
}
