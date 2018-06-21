#include "server.h"

void incantation(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Incantation\n");
}
