#include "server.h"

int ppo(server *server, int i, char **params)
{
    if (params[1] == NULL) {
        dprintf(server->client[i].fd, "ppo %d %d %d %d\n",
                server->client[i].id,
                server->client[i].posX,
                server->client[i].posY,
                server->client[i].orient + 1);
    }
    else {
        int id_player = atoi(params[1]);

        if (id_player < server->nb_player) {
            dprintf(server->client[i].fd, "ppo %d %d %d %d\n", id_player, server->client[id_player].posX,
                    server->client[id_player].posY, server->client[id_player].orient + 1);
        }
        else {
            dprintf(server->client[i].fd, "ko\n");
        }
    }
    return (0);
}
