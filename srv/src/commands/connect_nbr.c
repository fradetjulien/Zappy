#include "server.h"

void connect_nbr(server *server, int i, char UNUSED **params)
{
    team *tmp = server->team;

    while (tmp) {
        if (strcmp(tmp->name_team, server->client[i].name_team) == 0) {
            dprintf(server->client[i].fd, "%d\n", tmp->nb_player);
        }
        tmp = tmp->next;
    }
}
