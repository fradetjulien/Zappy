#include "server.h"

int broadcast(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Broadcast\n");
    return (0);
}
