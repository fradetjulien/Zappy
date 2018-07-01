/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "server.h"

static int execution(server *server, s_execution *tmp, int i)
{
	char **params;
	int cmd = 0;

	if (tmp->cmd != NULL && strlen(tmp->cmd) != 0) {
		for (cmd = 0; cmd < 20; cmd++) {
			if (strncmp(server->cmd[cmd], tmp->cmd,
				    strlen(server->cmd[cmd])) == 0 &&
			    strlen(tmp->cmd) != 0) {
				params = str_to_wordtab(tmp->cmd, ' ');
				if (server->command[cmd](server, i, params) == 0)
					tmp->cmd = NULL;
				return (1);
			}
		}
		if (cmd == 20) {
			dprintf(server->client[i].fd, "ko\n");
			tmp->cmd = NULL;
			return (1);
		}
	}
	return (0);
}
int execute_cmd(server *server)
{
	int i = 0;

	for (i = 0; i < server->actual; i++) {
		if (server->client[i].is_connected == 1) {
			if (server->client[i].time <= 0) {
				dprintf(server->client[i].fd, "dead\n");
				server->client[i].is_connected = 0;
				return (0);
			}
			/*if (win(server) == 1)
				exit(1);*/
			s_execution *tmp = server->client[i].exec;
			if (count_action(tmp) >= 10) {
				server->client[i].exec = NULL;
				return (0);
			}
			while (tmp) {
				execution(server, tmp, i);
				tmp = tmp->next;
			}
		}
	}
	return (0);
}
