/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** instructions_4.c
*/

#include "client.h"

int		content_map(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		name_all_teams(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		player_pos(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		player_lvl(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}

int		player_inventory(t_client *client, char *instruction)
{
	int	error = 0;

	error = send_instruction(client, instruction);
	if (error == -1) {
		return (-1);
	}
	return (0);
}
