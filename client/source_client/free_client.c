/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** free_client.c
*/

#include "client.h"

void		free_client(t_client client)
{
	free(client.port);
	free(client.team);
	free(client.socket);
}
