/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** instructions_3.c
*/

#include "client.h"

int		take(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		set(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		incantation(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		map_size(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		content_tile(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}
