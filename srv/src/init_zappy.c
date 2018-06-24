/*
** EPITECH PROJECT, 2018
** init_zappy.c
** File description:
** init_zappy.c
*/

#include "server.h"

int	fill_port(int ac, char **av)
{
	int	k = 0;
	int	i;
	int	j;

	for (i = 0; i < ac; i++) {
		if (strcmp(av[i], "-p") == 0 && strcmp(av[i + 1], "-x") != 0) {
			k = 1;
			for (j = 0; av[i + 1][j]; j++) {
				if ((av[i + 1][j] < '0') ||
				    (av[i + 1][j] > '9'))
					return 4242;
			}
		}
	}
	if (i == ac && k == 0)
		return 4242;
	return (atoi(av[2]));
}

team	*fill_name_teams(int ac, char **av)
{
	team *list = NULL;
	int i = 0;

	for (i = 0; i < ac; i++) {
		if (strcmp(av[i], "-n") == 0)
                        break ;
	}
	if (i == ac) {
		list = add_list_team("Team1", list, ac, av);
		list = add_list_team("Team2", list, ac, av);
		return (list);
	}
	i++;
	for (; i < ac; i++) {
		list = add_list_team(av[i], list, ac, av);
		if (strcmp(av[i + 1], "-c") == 0)
			break;
	}
	return list;
}

int	fill_nb_players(int ac, char **av)
{
	int	k = 0;
	int	i;
	int	j;

	for (i = 0; i < ac; ++i) {
		if (strcmp(av[i], "-c") == 0 && strcmp(av[i + 1], "-f") != 0) {
			k = 1;
			for (j = 0; av[i + 1][j]; j++) {
				if (av[i + 1][j] < '0' || av[i + 1][j] > '9')
					return 6;
			}
			break;
		}
	}
	if (i == ac && k == 0)
		return 6;
	return (atoi(av[i + 1]));
}

int	fill_max_client(int ac, char **av)
{
	int i = 0;
	while (i < ac) {
		if (strcmp(av[i], "-c") == 0)
			break ;
	}
	if (i == ac)
		return (6);
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
	if (av[i + 1] && i != ac)
	    return (atoi(av[i + 1]));
	else
		return 100;

}
