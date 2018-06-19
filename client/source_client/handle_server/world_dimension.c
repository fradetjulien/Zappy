/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** word_dimension.c
*/

#include "client.h"

int		world_dimension(t_client *client, char *instruct_received)
{
	char	*tmp;
	int	i = -1;

	client->abscissa = atoi(instruct_received);
	while (instruct_received[++i] != ' ' && instruct_received);
	tmp = &instruct_received[i];
	client->orderly = atoi(tmp);
	printf("%d %d\n", client->abscissa, client->orderly);
	return (0);
}
