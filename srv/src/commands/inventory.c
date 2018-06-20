#include "server.h"

void inventory(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Inventory\n");
}
