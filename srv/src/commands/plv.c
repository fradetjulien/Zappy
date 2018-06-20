#include "server.h"

void plv(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "plv %d\n", server->client[i].level);
}
