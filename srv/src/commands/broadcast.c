/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "server.h"

static void print_broadcast(server *server, int j, char **params, int i)
{
	int par = 2;

	if (j != i && server->client[j].is_connected == 1) {
		dprintf(server->client[j].fd,
		"message 0, %s", params[1]);
		while (params[par])
			if (params[par] != NULL) {
				dprintf(server->client[j].fd,
					" %s", params[par]);
				par++;
			}
	}

}

int broadcast(server *server, int i, char **params)
{
	double sec = get_time_micro();
	int j = 0;

	if ((sec - server->client[i].exec->time) >= (7 / server->frequency)) {
		if (params[1] == NULL)
			dprintf(server->client[i].fd, "ko\n");
		else {
			dprintf(server->client[i].fd, "ok\n");
			for (j = 0; j < server->nb_player; ++j) {
				print_broadcast(server, j, params, i);
			}
		}
		return (0);
	}
	return (1);
}
