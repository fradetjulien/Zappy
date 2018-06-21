#include "server.h"

void pin(server *server, int i, char **params)
{
    if (params[1] == NULL) {
        dprintf(server->client[i].fd, "%d %d %d %d %d %d %d %d %d %d\n",
                server->client[i].id, server->client[i].posX, server->client[i].posY,
                server->client[i].inventory->nb_food, server->client[i].inventory->nb_linemate,
                server->client[i].inventory->nb_deraumere, server->client[i].inventory->nb_sibur,
                server->client[i].inventory->nb_mendiane, server->client[i].inventory->nb_phiras,
                server->client[i].inventory->nb_thystame);
    }
    else {
        int id_player = atoi(params[1]);

        dprintf(server->client[i].fd, "%d %d %d %d %d %d %d %d %d %d\n",
                id_player, server->client[id_player].posX, server->client[id_player].posY,
                server->client[id_player].inventory->nb_food, server->client[id_player].inventory->nb_linemate,
                server->client[id_player].inventory->nb_deraumere, server->client[id_player].inventory->nb_sibur,
                server->client[id_player].inventory->nb_mendiane, server->client[id_player].inventory->nb_phiras,
                server->client[id_player].inventory->nb_thystame);
    }
}
