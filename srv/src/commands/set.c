#include "server.h"

int check_params_first(server *server, t_map *map, char **params, int i)
{
    if (strcmp(params[1], "linemate\n") == 0) {
        if (server->client[i].inventory->nb_linemate <= 0) {
            return (0);
        }
        server->client[i].inventory->nb_linemate--;
        map->rsrc->nb_linemate++;
        return (1);
    }
    else if (strcmp(params[1], "deraumere\n") == 0) {
        if (server->client[i].inventory->nb_deraumere <= 0)
            return (0);
        server->client[i].inventory->nb_deraumere--;
        map->rsrc->nb_deraumere++;
        return (1);
    }
    return (0);
}

int check_params_second(server *server, t_map *map, char **params, int i)
{
    if (strcmp(params[1], "phiras\n") == 0) {
        if (server->client[i].inventory->nb_phiras <= 0)
            return (0);
        server->client[i].inventory->nb_phiras--;
        map->rsrc->nb_phiras++;
        return (1);
    }
    else if (strcmp(params[1], "thystame\n") == 0) {
        if (server->client[i].inventory->nb_thystame <= 0)
            return (0);
        server->client[i].inventory->nb_thystame--;
        map->rsrc->nb_thystame++;
        return (1);
    }
    return (0);
}

int check_params_third(server *server, t_map *map, char **params, int i)
{
    if (strcmp(params[1], "sibur\n") == 0) {
        if (server->client[i].inventory->nb_sibur <= 0)
            return (0);
        server->client[i].inventory->nb_sibur--;
        map->rsrc->nb_sibur++;
        return (1);
    }
    else if (strcmp(params[1], "mendiane\n") == 0) {
        if (server->client[i].inventory->nb_mendiane <= 0)
            return (0);
        server->client[i].inventory->nb_mendiane--;
        map->rsrc->nb_mendiane++;
        return (1);
    }
    return (0);
}

int set(server *server, int i, char **params)
{
    t_map *map = server->map;
    double sec = get_time_micro();

    if ((sec - server->client[i].exec->time) >= (7 / server->frequency)) {
        if (params[1] == NULL)
            dprintf(server->client[i].fd, "ko\n");
        else {
            while (map) {
                if (map->node_pos->x == server->client[i].posX &&
                    map->node_pos->y == server->client[i].posY) {
                    if (check_params_first(server, map, params, i) == 1
                        || check_params_second(server, map, params, i) == 1
                        || check_params_third(server, map, params, i) == 1)
                        dprintf(server->client[i].fd, "ok\n");
                    else
                        dprintf(server->client[i].fd, "ko\n");
                }
                map = map->next;
            }
        }
        return (0);
    }
    return (1);
}
