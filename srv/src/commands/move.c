#include "server.h"

void forward(server *server, int i, char UNUSED **params)
{
    dprintf(server->client[i].fd, "ok\n");
}

void left(server *server, int i, char UNUSED **params)
{
    if (server->client[i].orient == NORTH)
        server->client[i].orient = WEST;
    else if (server->client[i].orient == EAST)
        server->client[i].orient = NORTH;
    else if (server->client[i].orient == SOUTH)
        server->client[i].orient = EAST;
    else if (server->client[i].orient == WEST)
        server->client[i].orient = SOUTH;
    dprintf(server->client[i].fd, "ok\n");
}

void right(server *server, int i, char UNUSED **params)
{
    if (server->client[i].orient == NORTH)
        server->client[i].orient = EAST;
    else if (server->client[i].orient == EAST)
        server->client[i].orient = SOUTH;
    else if (server->client[i].orient == SOUTH)
        server->client[i].orient = WEST;
    else if (server->client[i].orient == WEST)
        server->client[i].orient = NORTH;
    dprintf(server->client[i].fd, "ok\n");
}
