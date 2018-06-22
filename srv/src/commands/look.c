#include "server.h"

void	west(server *server, int i)
{
	
}

void	east(server *server, int i)
{
	
}

int	get_nb_player(server *srever, int x, int y)
{
	int	i = -1;
	int	j = 0;

	while (++i != server->nb_player) {
		if (server->client[i].posX == x && server->client[i].posY == y)
			j++;
	}
	return j;
}

int	get_nb_linemate(server *server, int x, int y)
{
	while (server->map) {
		if (server->map->node_pos->x == x && server->map->node_pos->y == y)
			return server->map->rsrc->nb_linemate;
		server->map = server->map->next;
	}
}

char	*get_ressources(server *server, int x, int y)
{
	int	player = 0;
	int	linemate = 0;
	int	deraumere = 0;
	int	sibur = 0;
	int	mendiane = 0;
	int	phiras = 0;
	int	thystame = 0;
	int	food = 0;
	
	player = get_nb_player(server, x, y);
	while (server->map) {
		if (server->map->node_pos->x == x && server->map->node_posY == y) {
			linemate = server->map->rsrc->nb_linemate;
			deraumere  = server->map->rsrc->nb_deraumere;
			sibur = server->map->rsrc->nb_sibur;
			mendiane = server->map->rsrc->nb_mendiane;
			phiras = server->map->rsrc->nb_phiras;
			thystame = server->map->rsrc->nb_thystame;
			food = server->map->rsrc->nb_food;	
		}
	}
}

void	north(server *server, int i)
{
	int	j = 0;
	int	eol = 3;
	int	k = 0;
	int	tmpX = server->client[i].posX;
	int	tmpY = server->client[i].posY;
	int	start_line = 0;
	char	*look;

	
	while (j != server->client[i].level) {
		tmpX -= 1;
		tmpY -= 1;
		start_line = tmpX;
		while (k < eol) {
			look = get_ressources(server, start_line, tmpY);
			start_line++;
			k++;
		}
		eol += 2;
		k = 0;
		j++;
	}
}

void	south(server *server, int i)
{
	int	j = 0;
	int	k = 0;
	int	eof = 3;
	int	tmpX = server->client[i].posX;
	int	tmpY = server->client[i].posY;
	int	start_line = 0;

	while (j != server->client[i].level) {
		tmpX += 1;
		tmpY += 1;
		start_line = tmpX;
		while (k < eof) {
			get_ressources(server, start_line, tmpY);
			start_line--;
			k++;
		}
		eof += 2;
		k = 0;
		j++;
 	}
}

void	west(server *server, int i)
{
	int	j = 0;
	int	k = 0;
	int	eof = 3;
	int	tmpX = server->client[i].posX;
	int	tmpY = server->client[i].posY;
	int	start_line = 0;

	while (j != server->client[i].level) {
		tmpX -= 1;
		tmpY += 1;
		start_line = tmpY;
		while (k < eof) {
			get_ressources(server, tmpX, start_line);
			start_line--;
			k++;
		}
		eof += 2;
		k = 0;
		j++;
	}
}

void	east(server *server, int i)
{
	int	j = 0;
	int	k = 0;
	int	eof = 3;
	int	tmpX = server->client[i].posX;
	int	tmpY = server->client[i].posY;
	int	start_line = 0;

	while (j != server->client[i].level) {
		tmpX += 1;
		tmpY -= 1;
		start_line = tmpY;
		while (k < eol) {
			get_ressources(server, tmpX, start_line);
			start_line++;
			k++;
		}
		eol += 2;
		k = 0;
		j++;
	}
}

void look(server *server, int i, char UNUSED **params)
{
	switch(server->client[i].orient) {
	case NORTH:
		north(server, i);
		break;
	case EAST:
		east(server, i);
		break;
	case WEST:
		west(server, i);
		break;
	case SOUTH:
		south(server, i);
		break;
	default:
		break;
	}
	dprintf(server->client[i].fd, "Look\n");
}
