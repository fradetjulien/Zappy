#include "server.h"

void look(server *server, int i)
{
    dprintf(server->client[i].fd, "Look\n");
}
