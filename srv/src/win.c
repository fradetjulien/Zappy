#include "server.h"

static void print_win(server *server, team *team)
{
	int j;

	for (j = 0; j < server->nb_player; ++j) {
		if (server->client[j].is_connected == 1)
			dprintf(server->client[j].fd, "%s win !\n", team->name_team);
	}
}

int	win(server *server)
{
	team *tmp = server->team;
	int win;
	int i = 0;

	while (tmp) {
		win = 0;
		for (i = 0; i < server->nb_player; ++i) {
			if (tmp->name_team && server->client[i].name_team) {
				if (strcmp(tmp->name_team, server->client[i].name_team) == 0
			    	&& server->client[i].level == 8)
						win++;
					if (win >= 6) {
						print_win(server, tmp);
						return (1);
					}
				}
			}
		tmp = tmp->next;
	}
	return (0);
}
