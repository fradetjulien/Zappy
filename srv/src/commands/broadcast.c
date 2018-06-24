#include "server.h"

int broadcast(server *server, int i, char **params)
{
    double sec = get_time_micro();

    if ((sec - server->client[i].exec->time) >= (7 / server->frequency)) {
        if (params[1] == NULL)
            dprintf(server->client[i].fd, "ko\n");
        else
            dprintf(server->client[i].fd, "Broadcast\n");
        return (0);
    }
    return (1);
}
