#include "server.h"

void plv(server *server, int i)
{
    dprintf(server->client[i].fd, "Plv\n");
}
