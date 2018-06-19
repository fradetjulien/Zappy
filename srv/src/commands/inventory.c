#include "server.h"

void inventory(server *server, int i)
{
    dprintf(server->client[i].fd, "Inventory\n");
}
