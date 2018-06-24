#include "server.h"

static void move_player(server *server, int j)
{
    switch (server->client[j].orient) {
        case NORTH:
            server->client[j].posY++;
            if (server->client[j].posY > server->height)
                server->client[j].posY = 0;
            break;
        case EAST:
            server->client[j].posX++;
            if (server->client[j].posX > server->width)
                server->client[j].posX = 0;
            break;
        case WEST:
            server->client[j].posX--;
            if (server->client[j].posX < 0)
                server->client[j].posX = server->width;
            break;
        case SOUTH:
            server->client[j].posY--;
            if (server->client[j].posY < 0)
                server->client[j].posY = server->height;
            break;
        default:
            break;
    }
}

int eject(server *server, int i, char UNUSED **params)
{
	int j = 0;
	int player = 0;
	double sec = get_time_micro();

	if ((sec - server->client[i].exec->time) >= (7 / server->frequency)) {
		while (j < server->nb_player) {
			if (server->client[j].posX == server->client[i].posX
			    && server->client[j].posY ==
			    server->client[i].posY && j != i) {
				dprintf(server->client[j].fd, "eject: %d\n",
			        server->client[j].orient);
				move_player(server, j);
				dprintf(server->client[i].fd, "ok\n");
				player = 1;
			}
			j++;
		}
		if (player == 0)
			dprintf(server->client[i].fd, "ko\n");
        return (0);
	}
    return (1);
}
