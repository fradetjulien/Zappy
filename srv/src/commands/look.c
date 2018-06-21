#include "server.h"

void look(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Look\n");
}
