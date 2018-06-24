#include "server.h"

int plv(server *server, int i, char **params)
{
    if (params[1] == NULL)
        dprintf(server->client[i].fd, "plv %d\n", server->client[i].level);
    else {
        int id_player = atoi(params[1]);

        if (id_player < server->nb_player)
            dprintf(server->client[i].fd, "plv %d\n", server->client[id_player].level);
        else
            dprintf(server->client[i].fd, "ko\n");
    }
    return (0);
}
