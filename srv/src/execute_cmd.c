#include "server.h"


int execute_cmd(server *server)
{
	int cmd = 0;
	int i = 0;
	char **params;

	for (i = 0; i < server->actual; i++) {
		if (server->client[i].is_connected == 1) {
			if (server->client[i].time <= 0) {
				dprintf(server->client[i].fd, "dead\n");
				server->client[i].is_connected = 0;
				return (0);
			}
			s_execution *tmp = server->client[i].exec;
			if (count_action(tmp) >= 10) {
				server->client[i].exec = NULL;
				break;
			}
			while (tmp) {
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
				tmp = tmp->next;
			}
		}
	}
	return (0);
}
