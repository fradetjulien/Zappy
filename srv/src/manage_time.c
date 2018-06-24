/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

void manage_time(server *server)
{
	int i = 0;

	while (i < server->nb_player) {
		server->client[i].time--;
		i++;
	}
}
