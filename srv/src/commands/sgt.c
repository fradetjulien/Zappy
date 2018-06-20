#include "server.h"

void sgt(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Sgt\n");
}
