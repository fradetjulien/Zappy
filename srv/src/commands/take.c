#include "server.h"

static int	check_on_map_first(t_map *tmp, server *server, char **params, int i)
{
	if (strcmp("food\n", params[1]) == 0 &&
	    tmp->rsrc->nb_food > 0) {
		tmp->rsrc->nb_food--;
		server->client[i].time += 126;
		server->client[i].inventory->nb_food += 126;
		dprintf(server->client[i].fd, "ok\n");
		return (1);
	}
	if (strcmp("linemate\n", params[1]) == 0 &&
	    tmp->rsrc->nb_linemate > 0) {
		tmp->rsrc->nb_food--;
		server->client[i].inventory->nb_linemate++;
        dprintf(server->client[i].fd, "ok\n");
        return (1);
	}
	return (0);
}

static int	check_on_map_second(t_map *tmp, server *server, char **params, int i)
{
	if (strcmp("mendiane\n", params[1]) == 0 &&
	    tmp->rsrc->nb_mendiane > 0) {
		tmp->rsrc->nb_mendiane--;
        server->client[i].inventory->nb_mendiane++;
        dprintf(server->client[i].fd, "ok\n");
        return (1);
	}
	if (strcmp("phiras\n", params[1]) == 0 &&
	    tmp->rsrc->nb_phiras > 0) {
		tmp->rsrc->nb_phiras--;
        server->client[i].inventory->nb_phiras++;
        dprintf(server->client[i].fd, "ok\n");
        return (1);
	}
	if (strcmp("thystame\n", params[1]) == 0 &&
	    tmp->rsrc->nb_thystame > 0) {
		tmp->rsrc->nb_thystame--;
        server->client[i].inventory->nb_thystame++;
        dprintf(server->client[i].fd, "ok\n");
        return (1);
	}
	return (0);
}

static int    check_on_map_third(t_map *tmp, server *server, char **params, int i)
{
    if (strcmp("deraumere\n", params[1]) == 0 &&
        tmp->rsrc->nb_deraumere > 0) {
        tmp->rsrc->nb_deraumere--;
        server->client[i].inventory->nb_deraumere++;
        dprintf(server->client[i].fd, "ok\n");
        return (1);
    }
    if (strcmp("sibur\n", params[1]) == 0 &&
        tmp->rsrc->nb_sibur > 0) {
        tmp->rsrc->nb_sibur--;
        server->client[i].inventory->nb_sibur++;
        dprintf(server->client[i].fd, "ok\n");
        return (1);
    }
    return (0);
}

void take(server *server, int i, char **params)
{
	t_map	*tmp = server->map;

	while (tmp) {
	    if (tmp->node_pos->x == server->client[i].posX &&
            tmp->node_pos->y == server->client[i].posY) {
	        if (check_on_map_first(tmp, server, params, i) == 0 &&
	            check_on_map_second(tmp, server, params, i) == 0 &&
                check_on_map_third(tmp, server, params, i) == 0)
	            dprintf(server->client[i].fd, "ko\n");
        }
	    tmp = tmp->next;
	}
}
