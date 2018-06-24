#include <sys/time.h>
#include "server.h"

int forward(server *server, int i, char UNUSED **params)
{
	double sec = get_time_micro();

	if ((sec - server->client[i].exec->time)
	    >= (7 / server->frequency)) {
		switch (server->client[i].orient) {
		case NORTH:
			server->client[i].posY++;
			if (server->client[i].posY > server->height)
				server->client[i].posY = 0;
			break;
		case EAST:
			server->client[i].posX++;
			if (server->client[i].posX > server->width)
				server->client[i].posX = 0;
			break;
		case WEST:
			server->client[i].posX--;
			if (server->client[i].posX < 0)
				server->client[i].posX = server->width;
			break;
		case SOUTH:
			server->client[i].posY--;
			if (server->client[i].posY < 0)
				server->client[i].posY = server->height;
			break;
		default:
			break;
		}
		dprintf(server->client[i].fd, "ok\n");
		return (0);
	}
	return (1);
}

int left(server *server, int i, char UNUSED **params)
{
	double sec = get_time_micro();

	if ((sec - server->client[i].exec->time)
	    >= (7 / server->frequency)) {
		if (server->client[i].orient == NORTH)
			server->client[i].orient = WEST;
		else if (server->client[i].orient == EAST)
			server->client[i].orient = NORTH;
		else if (server->client[i].orient == SOUTH)
			server->client[i].orient = EAST;
		else if (server->client[i].orient == WEST)
			server->client[i].orient = SOUTH;
		dprintf(server->client[i].fd, "ok\n");
		return (0);
	}
	return (1);
}

int right(server *server, int i, char UNUSED **params)
{
	double sec = get_time_micro();

	if ((sec - server->client[i].exec->time)
            >= (7 / server->frequency)) {
		if (server->client[i].orient == NORTH)
			server->client[i].orient = EAST;
		else if (server->client[i].orient == EAST)
			server->client[i].orient = SOUTH;
		else if (server->client[i].orient == SOUTH)
			server->client[i].orient = WEST;
		else if (server->client[i].orient == WEST)
			server->client[i].orient = NORTH;
		dprintf(server->client[i].fd, "ok\n");
		return (0);
	}
	return (1);
}
