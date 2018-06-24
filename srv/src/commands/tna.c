/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

int tna(server *server, int i, char UNUSED **params)
{
	team *tmp = server->team;

	while (tmp) {
		dprintf(server->client[i].fd, "tna %s\n", tmp->name_team);
		tmp = tmp->next;
	}
	return (0);
}
