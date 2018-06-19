#include "server.h"

void connect_nbr(server *server, int i)
{
    dprintf(server->client[i].fd, "connect_nbr\n");
}
