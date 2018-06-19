#include "server.h"

void sgt(server *server, int i)
{
    dprintf(server->client[i].fd, "Sgt\n");
}
