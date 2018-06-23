/*
** EPITECH PROJECT, 2018
** PSU_zappy_2014
** File description:
** instructions.c
*/

#include "client.h"

int		forward(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		right(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		left(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		look(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		inventory(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}
