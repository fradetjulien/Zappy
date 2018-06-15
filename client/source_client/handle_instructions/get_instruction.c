/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** get_instruction.c
*/

#include "client.h"

char		*get_instruction(t_client *client)
{
	char	*instruction = NULL;

	instruction = get_next_line(client->socket->fd);
	if (instruction == NULL)
		return (NULL);
	return (instruction);
}
