#include "server.h"

int msz(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "msz %d %d\n", server->width, server->height);
    return (0);
}
