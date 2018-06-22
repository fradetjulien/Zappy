/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** remaining_places.c
*/

#include "client.h"

int		remaining_places(char *instructReceived)
{
	if (atoi(instructReceived) >= 1) {
		instructReceived = print_instruction(instructReceived, 1);
		return (0);
	}
	return (-1);
}
