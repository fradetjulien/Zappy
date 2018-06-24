#include "server.h"

int bct(server *server, int i, char **params)
{
    t_map *tmp = server->map;
    int j = 0;

    while (params[j])
        j++;
    if (j != 3)
        dprintf(server->client[i].fd, "ko\n");
    else {
        while (tmp) {
            if (tmp->node_pos->x == atoi(params[1]) &&
                tmp->node_pos->y == atoi(params[2]))
                dprintf(server->client[i].fd, "bct %d %d %d linemate : %d %d %d %d %d %d\n",
                tmp->node_pos->x, tmp->node_pos->y, tmp->rsrc->nb_food,
                tmp->rsrc->nb_linemate, tmp->rsrc->nb_deraumere, tmp->rsrc->nb_sibur,
                tmp->rsrc->nb_mendiane, tmp->rsrc->nb_phiras, tmp->rsrc->nb_thystame);
            tmp = tmp->next;
        }
    }
    return (0);
}
