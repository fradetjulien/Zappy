/*
** EPITECH PROJECT, 2018
** init_list_team
** File description:
** init_list_team
*/

#include "server.h"

char	*fill_team(char *name_team)
{
	size_t i = 0;
	char	*team;
	
	while (!(name_team[i] >= 48 && name_team[i] <= 57))
                i++;
	team = malloc(sizeof(char) * i);
	i = 0;
	while (!(name_team[i] >= 48 && name_team[i] <= 57)) {
		team[i] = name_team[i];
                i++;
	}
	team[i] = 0;
	return (team);
}

int	number_team(char *name_team)
{
	size_t i = 0;
	size_t	len = 0;
	char	*nb_of_team;

	while (!(name_team[i] >= 48 && name_team[i] <= 57))
		i++;
	if (i == strlen(name_team))
		exit(84);
	nb_of_team = malloc(sizeof(char) * strlen(name_team) - i);
	while (name_team[i]) {
		nb_of_team[len] = name_team[i];
		len++;
		i++;
	}
	nb_of_team[len] = 0;
	return (atoi(nb_of_team));
}

team	*add_list_team(char *name_team, team *list)
{
	team        *new;
	team        *tmp;

	if ((new = malloc(sizeof(team))) == NULL)
		return (NULL);
	new->name_team = fill_team(name_team);
	new->nb_team = number_team(name_team);
	new->next = NULL;
	if (list == NULL)
		return (new);
	else {
		tmp = list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		return (list);
	}
}

void	show_list_team(team *list)
{
	team *tmp = list;

	while (tmp) {
		printf("name of team = %s\n", tmp->name_team);
		printf("id team = %d\n", tmp->nb_team);
		tmp = tmp->next;
	}
}
