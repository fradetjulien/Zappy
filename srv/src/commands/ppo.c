#include "server.h"

void ppo(server *server, int i, char **params)
{
    if (params[1] == NULL) {
        dprintf(server->client[i].fd, "ppo %d %d %d\n", server->client[i].posX,
                server->client[i].posY, server->client[i].orient + 1);
    }
    else {
        int id_player = atoi(params[1]);

        dprintf(server->client[i].fd, "ppo %d %d %d\n", server->client[id_player].posX,
                server->client[id_player].posY, server->client[id_player].orient + 1);
    }
}
