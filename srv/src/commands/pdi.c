#include "server.h"

int pdi(server *server)
{
    int j = 0;

    while (j < server->nb_player) {
        if (server->client[j].time <= 0 && server->client[j].is_connected == 1) {
            dprintf(server->client[j].fd, "pdi %d\n", server->client[j].id);
            server->client[j].is_connected = 0;
        }
        j++;
    }
    return (0);
}
