#include "server.h"

void plv(server *server, int i, char **params)
{
    if (params[1] == NULL)
        dprintf(server->client[i].fd, "plv %d\n", server->client[i].level);
    else {
        int id_player = atoi(params[1]);

        dprintf(server->client[i].fd, "plv %d\n", server->client[id_player].level);
    }
}
