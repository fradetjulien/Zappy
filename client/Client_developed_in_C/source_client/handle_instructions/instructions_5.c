/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** instructions_5.c
*/

#include "client.h"

int		time_unit_request(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		time_unit_modif(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}
