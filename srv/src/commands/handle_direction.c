/*
** EPITECH PROJECT, 2018
** server
** File description:
** server
*/

#include "server.h"

int     handle_orient(server *server, int i, int x, int y)
{
	if (server->client[i].orient == NORTH ||
	    server->client[i].orient == SOUTH)
		return (y);
	else
		return (x);
}

int handle_direction(server *server, int i)
{
	if (server->client[i].orient == NORTH ||
	    server->client[i].orient == WEST)
		return (1);
	else
		return (-1);
}

int handle_x(server *server, int x, int toward)
{
	if ((x + toward) < 0)
		return (server->width - 1);
	else if ((x + toward) > server->width - 1)
		return (0);
	else
		return (x + toward);
}

int handle_y(server *server, int y, int toward)
{
	if ((y + toward) < 0)
		return (server->height - 1);
	else if ((y + toward) > server->height - 1)
		return (0);
	else
		return (y + toward);
}

int     direction(server *server, int i, int x, int y)
{
	int     eof = 3;
	int     tmpX = server->client[i].posX;
	int     tmpY = server->client[i].posY;
	int st = 0;
	char **rsrc = create_tab_ressources();
	int toward = handle_direction(server, i);

	if (rsrc == NULL)
		return (-1);
	get_ressources(server, tmpX, tmpY, rsrc);
	add_elem_in_look(server, ",");
	for (int j = 0; j < server->client[i].level; j++) {
		tmpX = handle_x(server, tmpX, x);
		tmpY = handle_y(server, tmpY, y);
		st = handle_orient(server, i, tmpX, tmpY);
		for (int k = 0; k < eof; k++) {
			get_ressources(server, tmpX, st, rsrc);
			if (k + 1 != eof)
				add_elem_in_look(server, ",");
			manage_dire(server, &st, toward, i);
		}
		eof += 2;
	}
	return (0);
}
