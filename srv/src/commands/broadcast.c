#include "server.h"

void broadcast(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Broadcast\n");
}
