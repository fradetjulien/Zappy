#include "server.h"

void mct(server *server, int i, char UNUSED **params)
{
    t_map *tmp = server->map;

    while (tmp) {
        dprintf(server->client[i].fd, "bct %d %d %d %d %d %d %d %d %d\n",
        tmp->node_pos->x, tmp->node_pos->y, tmp->rsrc->nb_food,
        tmp->rsrc->nb_linemate, tmp->rsrc->nb_deraumere, tmp->rsrc->nb_sibur,
        tmp->rsrc->nb_mendiane, tmp->rsrc->nb_phiras, tmp->rsrc->nb_thystame);
        tmp = tmp->next;
    }
}
