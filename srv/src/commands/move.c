#include "server.h"

void forward(server *server, int i)
{
    dprintf(server->client[i].fd, "Forward\n");
}

void left(server *server, int i)
{
    dprintf(server->client[i].fd, "Left\n");
}

void right(server *server, int i)
{
    dprintf(server->client[i].fd, "Right\n");
}
