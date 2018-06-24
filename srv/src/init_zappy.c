/*
** EPITECH PROJECT, 2018
** init_zappy.c
** File description:
** init_zappy.c
*/

#include "server.h"

int	verification_args(char **av)
{
	if (strcmp(av[1], "-p") != 0 ||
	    strcmp(av[3], "-x") != 0 ||
	    strcmp(av[5], "-y") != 0 ||
	    strcmp(av[7], "-n") != 0 )
		return -1;
	return (0);
}

int	fill_port(char **av)
{
	return (atoi(av[2]));
}

int	fill_width(char **av)
{
	return (atoi(av[4]));
}

int	fill_height(char **av)
{
	return (atoi(av[6]));
}

team	*fill_name_teams(int ac, char **av)
{
	team *list = NULL;

	for (int i = 8; i < ac; ++i) {
		list = add_list_team(av[i], list, ac, av);
		if (strcmp(av[i + 1], "-c") == 0)
			break ;
	}
	return list;
}

int	fill_nb_players(int ac, char **av) 
{
	int i = 0;
	for (i = 8; i < ac; ++i) {
		if (strcmp(av[i], "-c") == 0)
			break;
	}
	return (atoi(av[i + 1]));
}

int	fill_max_client(int ac, char **av)
{
	int i = 0;

	while (i < ac) {
		if (strcmp(av[i], "-n") == 0)
			break ;
	}
	return (atoi(av[i + 1]));
}

int	fill_frequency(int ac, char **av)
{
	int i = 0;

	while (i < ac) {
		if (strcmp(av[i], "-f") == 0)
			break ;
		i++;
	}
	return (atoi(av[i + 1]));
}
