/*
** EPITECH PROJECT, 2018
** handle_client
** File description:
** handle_client
*/

#include "server.h"
#include "ring_buffer.h"

int first_cmd(char *buffer, int fd, server *server)
{
	team *tmp = server->team;
	while (tmp) {
		if (strncmp(tmp->name_team, buffer,
			   strlen(tmp->name_team)) == 0) {
			tmp->nb_player--;
			dprintf(fd, "%d\n", tmp->nb_player);
			dprintf(fd, "%d %d\n", server->width, server->height);
			server->client[fd].is_connected = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	manage_client(server *server, fd_set rdfs)
{
	int i;
	char buf[4096];
	int r;

        for (i = 0; i < server->actual; i++) {
            if (FD_ISSET(server->client[i].fd, &rdfs)) {
                    memset(buf, 0, 4096);
			r = read(server->client[i].fd, buf, 4096);
			if (r == 0) {
				printf("Client disconnected : %d\n", server->client[i].fd);
				close(server->client[i].fd);
				server->actual--;
			}
			if (strlen(buf) != 0)
				printf("buf = %s\n", buf);
			if (server->client[i].is_connected == 0) {
				if (first_cmd(buf, server->client[i].fd, server) == 0)
					server->client[i].is_connected = 1;
				else
					dprintf(server->client[i].fd, "ko\n");
				}
			for (int cmd = 0; cmd < 20; cmd++) {
					if (strncmp(server->cmd[cmd], buf,
						strlen(server->cmd[cmd])) == 0) {
							server->command[cmd](server, i);
						}
			}
                break;
            }
        }
}
