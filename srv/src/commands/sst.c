#include "server.h"

int sst(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "sst\n");
    return (0);
}
