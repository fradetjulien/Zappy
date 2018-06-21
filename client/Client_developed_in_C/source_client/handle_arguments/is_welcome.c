/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** is_welcome.c
*/

#include "client.h"

int		is_welcome(char *instruction)
{
	if (instruction == NULL) {
		return (-1);
	}
	else if (strcmp(instruction, "WELCOME") != 0) {
		return (-1);
	}
	else {
		return (0);
	}
	return (-1);
}
