#include "server.h"

void msz(server *server, int i)
{
    dprintf(server->client[i].fd, "msz %d %d\n", server->width, server->height);
}
