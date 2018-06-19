#include "server.h"

void broadcast(server *server, int i)
{
    dprintf(server->client[i].fd, "Broadcast\n");
}
