/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

static void print_pin(server *server, int i)
{
	dprintf(server->client[i].fd, "pin %d %d %d %d %d %d %d %d %d %d\n",
	server->client[i].id,
	server->client[i].posX,
	server->client[i].posY,
	server->client[i].inventory->nb_food,
	server->client[i].inventory->nb_linemate,
	server->client[i].inventory->nb_deraumere,
	server->client[i].inventory->nb_sibur,
	server->client[i].inventory->nb_mendiane,
	server->client[i].inventory->nb_phiras,
	server->client[i].inventory->nb_thystame);
}

static void print_pin2(server *server, int i, int id_player)
{
	dprintf(server->client[i].fd, "pin %d %d %d %d %d %d %d %d %d %d\n",
	id_player,
	server->client[id_player].posX,
	server->client[id_player].posY,
	server->client[id_player].inventory->nb_food,
	server->client[id_player].inventory->nb_linemate,
	server->client[id_player].inventory->nb_deraumere,
	server->client[id_player].inventory->nb_sibur,
	server->client[id_player].inventory->nb_mendiane,
	server->client[id_player].inventory->nb_phiras,
	server->client[id_player].inventory->nb_thystame);
}

int pin(server *server, int i, char **params)
{
	if (params[1] == NULL) {
		print_pin(server, i);
	}
	else {
		int id_player = atoi(params[1]);

		if (id_player < server->nb_player) {
			print_pin2(server, i, id_player);
		}
		else
			dprintf(server->client[i].fd, "ko\n");
	}
	return (0);
}
