/*
** EPITECH PROJECT, 2018
** look2
** File description:
** look2
*/

#include "server.h"

int check_orient(server *server, int i)
{
	if (server->client[i].orient == NORTH
		|| server->client[i].orient == SOUTH)
		return (1);
	else
		return (-1);
}

int     get_nb_player(server *server, int x, int y)
{
	int     i = -1;
	int     j = 0;

	while (++i != server->nb_player) {
		if (server->client[i].posX == x && server->client[i].posY == y)
			j++;
        }
        return j;
}

char **create_tab_ressources(void)
{
	char **tmp = malloc(sizeof(char *) * 8);

	if (tmp == NULL)
		return (NULL);
	tmp[0] = strdup("player");
	tmp[1] = strdup("linemate");
	tmp[2] = strdup("deraumere");
	tmp[3] = strdup("sibur");
	tmp[4] = strdup("mendiane");
	tmp[5] = strdup("phiras");
	tmp[6] = strdup("thystame");
	tmp[7] = strdup("food");
	for (int i = 0; i < 8; i++) {
		if (tmp[i] == NULL)
			return (NULL);
	}
	return (tmp);
}

t_look  *add_elem_in_look(server *server, const char *str)
{
	t_look  *new = malloc(sizeof(t_look));
	t_look  *tmp = server->look;

	if (new == NULL)
		return (NULL);
	new->str = str;
	new->next = NULL;
	if (tmp == NULL) {
		tmp = new;
		return (new);
	}
	else {
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		return (server->look);
	}
}

void manage_dire(server *server, int *st, int toward, int i)
{
	if (check_orient(server, i) == 1)
		*st = handle_y(server, *st, toward);
	else
		*st = handle_x(server, *st, toward);
}
