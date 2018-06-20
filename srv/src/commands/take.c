#include "server.h"

void take(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Take\n");
}
