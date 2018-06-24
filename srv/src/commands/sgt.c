#include "server.h"

int sgt(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "sgt %d\n", server->frequency);
    return (0);
}
