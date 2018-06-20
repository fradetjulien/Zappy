#include "server.h"

void mct(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "Mct\n");
}
