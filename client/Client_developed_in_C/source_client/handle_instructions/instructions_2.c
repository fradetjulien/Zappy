/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** instructions_2.c
*/

#include "client.h"

int		bro(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		broadcast(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		cmd_connect(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		cmd_fork(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		eject(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}
