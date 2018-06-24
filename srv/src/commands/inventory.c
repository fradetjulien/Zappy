/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

int inventory(server *server, int i, char UNUSED **params)
{
	double sec = get_time_micro();

	if ((sec - server->client[i].exec->time) >= (1 / server->frequency)) {
		dprintf(server->client[i].fd,
		"[food %d,linemate %d,deraumere %d,",
		server->client[i].time / 126,
		server->client[i].inventory->nb_linemate,
		server->client[i].inventory->nb_deraumere);
		dprintf(server->client[i].fd,
		"sibur %d,mendiane %d,phiras %d,thystame %d]\n",
		server->client[i].inventory->nb_sibur,
		server->client[i].inventory->nb_mendiane,
		server->client[i].inventory->nb_phiras,
		server->client[i].inventory->nb_thystame);
		return (0);
	}
	return (1);
}
