#include "server.h"

void pdi(server *server, int UNUSED i, char UNUSED **params)
{
    int j = 0;

    while (j < server->nb_player) {
        if (server->client[j].time == 0) {
            dprintf(server->client[j].fd, "pdi %d\n", server->client[i].id);
            server->client[j].is_connected = 0;
        }
        j++;
    }
}
