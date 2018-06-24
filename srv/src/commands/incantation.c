#include "server.h"

static int check_players(server *server, int i, int players)
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

void evolution_1(server *server, int i, int *incantation)
{
	t_map *map = server->map;
	while (map) {
		if (map->node_pos->x == server->client[i].posX &&
		    map->node_pos->y == server->client[i].posY) {
			switch (server->client[i].level) {
			case 1:
				if (map->rsrc->nb_linemate == 1) {
					*incantation = 1;
				}
				break;
			case 2:
				if (map->rsrc->nb_linemate == 1 &&
				    map->rsrc->nb_deraumere == 1 &&
				    map->rsrc->nb_sibur == 1 &&
				    check_players(server, i, 2) == 0) {
					*incantation = 1;
				}
				break;
			default:
				break;
			}
		}
		map = map->next;
	}
}

void evolution_2(server *server, int i, int *incantation)
{
	t_map *map = server->map;

	while (map) {
		if (map->node_pos->x == server->client[i].posX &&
		    map->node_pos->y == server->client[i].posY) {
			switch (server->client[i].level) {
			case 3:
				if (map->rsrc->nb_linemate == 2 &&
				    map->rsrc->nb_sibur == 1 &&
				    map->rsrc->nb_phiras == 2 &&
				    check_players(server, i, 2) == 0) {
					*incantation = 1;
				}
				break;
			case 4:
				if (map->rsrc->nb_linemate == 1 &&
				    map->rsrc->nb_deraumere == 1 &&
				    map->rsrc->nb_sibur == 2 &&
				    map->rsrc->nb_phiras == 1 &&
				    check_players(server, i, 4) == 0) {
					*incantation = 1;
				}
				break;
			default:
				break;
			}
		}
		map = map->next;
	}
}

void evolution_3(server *server, int i, int *incantation)
{
	t_map *map = server->map;

	while (map) {
		if (map->node_pos->x == server->client[i].posX &&
		    map->node_pos->y == server->client[i].posY) {
			switch (server->client[i].level) {
			case 5:
				if (map->rsrc->nb_linemate == 1 &&
				    map->rsrc->nb_deraumere == 2 &&
				    map->rsrc->nb_sibur == 1 &&
				    map->rsrc->nb_mendiane == 3 &&
				    check_players(server, i, 4) == 0) {
					*incantation = 1;
				}
				break;
			case 6:
				if (map->rsrc->nb_linemate == 1 &&
				    map->rsrc->nb_deraumere == 2 &&
				    map->rsrc->nb_sibur == 3 &&
				    map->rsrc->nb_phiras == 1 &&
				    check_players(server, i, 6) == 0) {
					*incantation = 1;
				}
				break;
			default:
				break;
			}
		}
		map = map->next;
	}
}

void evolution_4(server *server, int i, int *incantation)
{
	t_map *map = server->map;

	while (map) {
		if (map->node_pos->x == server->client[i].posX &&
		    map->node_pos->y == server->client[i].posY) {
			switch (server->client[i].level) {
			case 7:
				if (map->rsrc->nb_linemate == 2 &&
				    map->rsrc->nb_deraumere == 2 &&
				    map->rsrc->nb_sibur == 2 &&
				    map->rsrc->nb_mendiane == 2 &&
				    map->rsrc->nb_phiras == 2 &&
				    map->rsrc->nb_thystame == 1 &&
				    check_players(server, i, 6) == 0) {
					*incantation = 1;
				}
			default:
				break;
			}
		}
		map = map->next;
	}
}

int incantation(server *server, int i, char UNUSED **params)
{
	int incantation = 0;
	double sec = get_time_micro();

	evolution_1(server, i, &incantation);
	evolution_2(server, i, &incantation);
	evolution_3(server, i, &incantation);
	evolution_4(server, i, &incantation);
	if ((sec - server->client[i].exec->time)
	    >= (300 / server->frequency)) {
		if (incantation == 1) {
			server->client[i].level++;
			dprintf(server->client[i].fd, "Elevation underway\nCurrent level: %d\n",
				server->client[i].level);
		}
		else
			dprintf(server->client[i].fd, "ko\n");
		return (0);
	}
	return (1);
}
