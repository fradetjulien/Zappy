/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

int	fill_width(int ac, char **av)
{
	int	k = 0;
	int	i;
	int	j;

	for (i = 0; i < ac; i++) {
		if (strcmp(av[i], "-x") == 0 &&
		    strcmp(av[i + 1], "-y") != 0) {
			k = 1;
			for (j = 0; av[i + 1][j]; j++) {
				if (av[i + 1][j] < '0' ||
				    av[i + 1][j] > '9')
					return 20;
			}
		}
	}
	if (i == ac && k == 0)
		return 20;
	return (atoi(av[4]));
}

int	fill_height(int ac, char **av)
{
	int	k = 0;
	int	i;
	int	j;

	for (i = 0; i < ac; i++) {
		if (strcmp(av[i], "-y") == 0 &&
		    strcmp(av[i + 1], "-n") != 0) {
			k = 1;
			for (j = 0; av[i + 1][j]; j++) {
				if ((av[i + 1][j] < '0') ||
				    (av[i + 1][j] > '9'))
					return 20;
			}
		}
	}
	if (i == ac && k == 0)
		return 20;
	return (atoi(av[6]));
}
