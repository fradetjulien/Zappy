/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** isWriteArguments.c
*/

#include "client.h"

int		isWriteArguments(char **av)
{
	if ((strcmp(av[0], "./zappy_ai") != 0) ||
	    (strcmp(av[1], "-p") != 0) ||
	    (strcmp(av[3], "-n") != 0) ||
	    (strcmp(av[5], "-h") != 0)) {
		return (-1);
	}
	if (isHostname(av[6]) != 0 || isPort(av[2]) != 0) {
		return (-1);
	}
	return (0);
}
