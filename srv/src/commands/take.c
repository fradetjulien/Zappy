#include "server.h"

void	check_on_map_first(t_map *tmp, server *server, char **params, int j)
{
	if (strcmp("food\n", params[j]) == 0 &&
	    tmp->map->rsrc->nb_food > 0) {
		tmp->map->rsrc->nb_food--;
		server->client->time++;
	}
	if (strcmp("linemate\n", params[j]) == 0 &&
	    tmp->map->rsrc->nb_linemate > 0) {
		tmp->map->rsrc->nb_food--;
		server->client->time++;
	}
	if (strcmp("deraumere\n", params[j]) == 0 &&
	    tmp->map->rsrc->nb_deraumere > 0) {
		tmp->map->rsrc->nb_deraumere--;
		server->client->time++;
	}
	if (strcmp("sibur\n", params[j]) == 0 &&
	    tmp->map->rsrc->nb_sibur > 0) {
		tmp->map->rsrc->nb_sibur--;
		server->client->time++;
	}
}

void	check_on_map_second(t_map *tmp, server *server, char **params, int j)
{
	if (strcmp("mendiane\n", params[j]) == 0 &&
	    tmp->map->rsrc->nb_mendiane > 0) {
		tmp->map->rsrc->nb_mendiane--;
		server->client->time++;
	}
	if (strcmp("phiras\n", params[j]) == 0 &&
	    tmp->map->rsrc->nb_phiras > 0) {
		tmp->map->rsrc->nb_phiras--;
		server->client->time++;
	}
	if (strcmp("thystmane\n", params[j]) == 0 &&
	    tmp->map->rsrc->nb_thystmane > 0) {
		tmp->map->rsrc->nb_thystmane--;
		server->client->time++;
	}
}

void take(server *server, int i, char **params)
{
	t_map	*tmp = server->map;
	int		j = 0;

	while (params[j])
		j++;
	if (j < 4 || j > 9)
		dprintf(server->client[i].fd, "ko\n");
	else {
		while (tmp) {
			if (tmp->node_pos->x == server->posX &&
			    tmp->node_pos->y == server->posY) {
				check_on_map_first(tmp, server, params, j);
				check_on_map_second(tmp, server, params, j);
			}
			tmp = tmp->next;
		}
	}
}
