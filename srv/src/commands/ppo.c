#include "server.h"

void ppo(server *server, int i)
{
    dprintf(server->client[i].fd, "Ppo\n");
}
