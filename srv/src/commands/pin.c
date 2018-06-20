#include "server.h"

void pin(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Pin\n");
}
