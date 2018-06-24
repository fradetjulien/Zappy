/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

static void print_ppo(server *server, int i)
{
	dprintf(server->client[i].fd, "ppo %d %d %d %d\n",
	server->client[i].id,
	server->client[i].posX,
	server->client[i].posY,
	server->client[i].orient + 1);
}

static void print_ppo2(server *server, int i, int id_player)
{
	if (id_player < server->nb_player) {
		dprintf(server->client[i].fd, "ppo %d %d %d %d\n",
		id_player, server->client[id_player].posX,
		server->client[id_player].posY,
		server->client[id_player].orient + 1);
	}
	else {
		dprintf(server->client[i].fd, "ko\n");
	}

}

int ppo(server *server, int i, char **params)
{
	int id_player;

	if (params[1] == NULL) {
		print_ppo(server, i);
	}
	else {
		id_player = atoi(params[1]);
		print_ppo2(server, i, id_player);
	}
	return (0);
}
