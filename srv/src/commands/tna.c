#include "server.h"

void tna(server *server, int i, char UNUSED **params)
{
    team *tmp = server->team;

    while (tmp) {
        dprintf(server->client[i].fd, "tna %s\n", tmp->name_team);
        tmp = tmp->next;
    }
}
