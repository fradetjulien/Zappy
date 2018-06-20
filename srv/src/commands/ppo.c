#include "server.h"

void ppo(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "ppo %d %d %d\n", server->client[i].posX,
    server->client[i].posY, server->client[i].orient + 1);
}
