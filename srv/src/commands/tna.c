#include "server.h"

void tna(server *server, int i)
{
    dprintf(server->client[i].fd, "Tna\n");
}
