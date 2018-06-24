/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "server.h"

int check_players(server *server, int i, int players)
{
	int j = 0;
	int count_players = 0;

	while (j < server->nb_player) {
		if (server->client[j].posX == server->client[i].posX &&
			server->client[j].posY == server->client[i].posY &&
			server->client[j].level == server->client[i].level)
			count_players++;
		j++;
	}
	if (count_players != players)
		return (0);
	else
		return (1);
}

void evolution_6(server *server, int i, int *incantation, t_map *map)
{
	if (server->client[i].level == 6) {
		if (map->rsrc->nb_linemate == 1 &&
		map->rsrc->nb_deraumere == 2 &&
		map->rsrc->nb_sibur == 3 &&
		map->rsrc->nb_phiras == 1 &&
		map->rsrc->nb_thystame == 0 &&
		map->rsrc->nb_mendiane == 0 &&
		check_players(server, i, 6) == 0) {
			*incantation = 1;
			return;
		}
	}
}

void evolution_7(server *server, int i, int *incantation, t_map *map)
{
	if (server->client[i].level == 7) {
		if (map->rsrc->nb_linemate == 2 &&
		map->rsrc->nb_deraumere == 2 &&
		map->rsrc->nb_sibur == 2 &&
		map->rsrc->nb_mendiane == 2 &&
		map->rsrc->nb_phiras == 2 &&
		map->rsrc->nb_thystame == 1 &&
		check_players(server, i, 6) == 0) {
			*incantation = 1;
		}
	}
}

void evolution(server *server, int i, int *incantation)
{
	t_map *map = server->map;

	while (map) {
		if (map->node_pos->x == server->client[i].posX &&
		map->node_pos->y == server->client[i].posY) {
			evolution_1(server, i, incantation, map);
			evolution_2(server, i, incantation, map);
			evolution_3(server, i, incantation, map);
			evolution_4(server, i, incantation, map);
		}
		map = map->next;
	}
}

int incantation(server *server, int i, char UNUSED **params)
{
	int incantation = 0;
	double sec;
	static int print = 0;

	evolution(server, i, &incantation);
	if (print == 0) {
		if (incantation == 1)
			dprintf(server->client[i].fd, "Elevation underway\n");
		else
			dprintf(server->client[i].fd, "ko\n");
		print = 1;
	}
	sec = get_time_micro();
	if ((sec - server->client[i].exec->time)
	>= (300 / server->frequency)) {
		if (incantation == 1) {
			server->client[i].level++;
			dprintf(server->client[i].fd, "Current level: %d\n",
			server->client[i].level);
		}
		else
			dprintf(server->client[i].fd, "ko\n");
		print = 0;
		return (0);
	}
	return (1);
}
