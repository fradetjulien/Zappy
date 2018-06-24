#include "../../include/server.h"

int	get_nb_player(server *server, int x, int y)
{
	int	i = -1;
	int	j = 0;

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

t_look	*add_elem_in_look(server	*server, const char *str)
{
	t_look	*new = malloc(sizeof(t_look));
	t_look	*tmp = server->look;

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

int add_case(server *server, const int *ressources, char **rsrc)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < ressources[i]; j++) {
			server->look = add_elem_in_look(server, rsrc[i]);
			if (server->look == NULL)
				return (-1);
		}
	}
	return (0);
}

int	*get_ressources(server *server, int x, int y, char **rsrc)
{
	int *ressources;
	t_map	*tmp = server->map;

	ressources = malloc(sizeof(int) * 8);
	if (ressources == NULL)
		return (NULL);
	ressources[0] = get_nb_player(server, x, y);
	while (tmp) {
		if (tmp->node_pos->x == x && tmp->node_pos->y == y) {
			ressources[1] = server->map->rsrc->nb_linemate;
			ressources[2]  = server->map->rsrc->nb_deraumere;
			ressources[3] = server->map->rsrc->nb_sibur;
			ressources[4] = server->map->rsrc->nb_mendiane;
			ressources[5] = server->map->rsrc->nb_phiras;
			ressources[6] = server->map->rsrc->nb_thystame;
			ressources[7] = server->map->rsrc->nb_food;
		}
		tmp = tmp->next;
	}
	add_case(server, ressources, rsrc);
	return (ressources);
}

int	handle_orient(server *server, int i, int x, int y)
{
	if (server->client[i].orient == NORTH || server->client[i].orient == SOUTH)
		return (y);
	else
		return (x);
}

int handle_direction(server *server, int i)
{
	if (server->client[i].orient == NORTH || server->client[i].orient == WEST)
		return (1);
	else
		return (-1);
}

int handle_xdirection(server *server, int x, int toward)
{
	if ((x + toward) < 0)
		return (server->width - 1);
	else if ((x + toward) > server->width - 1)
		return (0);
	else
		return (x + toward);
}

int handle_ydirection(server *server, int y, int toward)
{
	if ((y + toward) < 0)
		return (server->height - 1);
	else if ((y + toward) > server->height - 1)
		return (0);
	else
		return (y + toward);
}

int check_orient(server *server, int i)
{
	if (server->client[i].orient == NORTH || server->client[i].orient == SOUTH)
		return (1);
	else
		return (-1);
}

int	direction(server *server, int i, int x, int y)
{
	int	eof = 3;
	int	tmpX = server->client[i].posX;
	int	tmpY = server->client[i].posY;
	int start_line = 0;
	char **rsrc = create_tab_ressources();
	int toward = handle_direction(server, i);

	if (rsrc == NULL)
		return (-1);
	for (int j = 0; j < server->client[i].level; j++) {
		tmpX = handle_xdirection(server, tmpX, x);
		tmpY = handle_ydirection(server, tmpY, y);
		start_line = handle_orient(server, i, tmpX, tmpY);
		for(int k = 0; k < eof; k++) {
			get_ressources(server, tmpX, start_line, rsrc);
			if (k + 1 != eof)
				add_elem_in_look(server, ",");
			if (check_orient(server, i) == 1)
				start_line = handle_ydirection(server, start_line, toward);
			else
				start_line = handle_xdirection(server, start_line, toward);
		}
		eof += 2;
	}
	return (0);
}

void	send_vision(server *server, int i)
{
	dprintf(server->client[i].fd, "[ ");
	for (t_look *tmp = server->look; tmp != NULL; tmp = tmp->next) {
		if (strcmp(tmp->str, ",") == 0) {
			dprintf(server->client[i].fd, ", ");
		}
		else if (tmp->next == NULL) {
			dprintf(server->client[i].fd, "%s ]\n", tmp->str);
		}
		else {
			if (tmp->next != NULL && strcmp(tmp->next->str, ",") == 0)
				dprintf(server->client[i].fd, "%s", tmp->str);
			else
				dprintf(server->client[i].fd, "%s ", tmp->str);
		}
	}
}

int look(server *server, int i, char UNUSED **params)
{
	double sec = get_time_micro();

	server->look = NULL;
	server->client[i].orient = EAST;
	server->client[i].posX = 19;
	server->client[i].posY = 19;
        if ((sec - server->client[i].exec->time) >= (7 / server->frequency)) {
		switch(server->client[i].orient) {
		case NORTH:
			if (direction(server, i, -1, -1) == -1)
				exit(84);
			break;
		case EAST:
			if (direction(server, i, 1, -1) == -1)
				exit(84);
			break;
		case WEST:
			if (direction(server, i, -1, 1) == -1)
				exit(84);
			break;
		case SOUTH:
			if (direction(server, i, 1, 1) == -1)
				exit(84);
			break;
		default:
			break;
		}
		send_vision(server, i);
		return (0);
	}
	return (1);
}
