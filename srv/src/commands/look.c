/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

int add_case(server *server, const int *ressources, char **rsrc)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < ressources[i]; j++) {
			server->look = add_elem_in_look(server, rsrc[i]);
			if (server->look == NULL) {
				return (-1);
			}
		}
	}
	return (0);
}

int	*get_ressources(server *server, int x, int y, char **rsrc)
{
	int *ressources;
	t_map	*tmp = server->map;

	ressources = malloc(sizeof(int) * 8);
	if (ressources == NULL)
		return (NULL);
	ressources[0] = get_nb_player(server, x, y);
	while (tmp) {
		if (tmp->node_pos->x == x && tmp->node_pos->y == y) {
			ressources[1] = tmp->rsrc->nb_linemate;
			ressources[2]  = tmp->rsrc->nb_deraumere;
			ressources[3] = tmp->rsrc->nb_sibur;
			ressources[4] = tmp->rsrc->nb_mendiane;
			ressources[5] = tmp->rsrc->nb_phiras;
			ressources[6] = tmp->rsrc->nb_thystame;
			ressources[7] = tmp->rsrc->nb_food;
		}
		tmp = tmp->next;
	}
	add_case(server, ressources, rsrc);
	return (ressources);
}

void	send_vision(server *server, int i)
{
	dprintf(server->client[i].fd, "[");
	for (t_look *tmp = server->look; tmp != NULL; tmp = tmp->next) {
		if (strcmp(tmp->str, ",") == 0) {
			dprintf(server->client[i].fd, ",");
		}
		else if (tmp->next == NULL) {
			dprintf(server->client[i].fd, "%s]\n", tmp->str);
		}
		else {
			if (tmp->next != NULL &&
				strcmp(tmp->next->str, ",") == 0)
				dprintf(server->client[i].fd, "%s", tmp->str);
			else
				dprintf(server->client[i].fd, "%s ", tmp->str);
		}
	}
}

static void manage_look(server *server, int i)
{
	switch (server->client[i].orient) {
	case NORTH:
		if (direction(server, i, -1, -1) == -1)
			exit(84);
		break;
	case EAST:
		if (direction(server, i, 1, -1) == -1)
			exit(84);
		break;
	case WEST:
		if (direction(server, i, -1, 1) == -1)
			exit(84);
		break;
	case SOUTH:
		if (direction(server, i, 1, 1) == -1)
			exit(84);
		break;
	default:
		break;
	}
}

int look(server *server, int i, char UNUSED **params)
{
	double sec = get_time_micro();

	server->look = NULL;
	if ((sec - server->client[i].exec->time) >= (7 / server->frequency)) {
		manage_look(server, i);
		send_vision(server, i);
		return (0);
	}
	return (1);
}
