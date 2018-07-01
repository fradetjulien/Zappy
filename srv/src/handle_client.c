/*
** EPITECH PROJECT, 2018
** handle_client
** File description:
** handle_client
*/

#include "server.h"

static int is_graph(char *buffer, int fd, server *server)
{
	if (strncmp("graph\n", buffer, strlen("graph\n")) == 0) {
		printf("on y est\n");
		server->client[server->actual - 1].inventory->nb_food = 999999;
        server->client[server->actual - 1].name_team = strdup("graph");
		server->client[server->actual - 1].id = 12000;
		server->client[server->actual - 1].posX = -1;
		server->client[server->actual - 1].posY = -1;
		dprintf(fd, "42\n");
		dprintf(fd, "%d %d\n", server->width, server->height);
		return (1);
	}
	return (0);
}

static int first_cmd(char *buffer, int fd, server *server, int i)
{
	team *tmp = server->team;

	if (is_graph(buffer, fd, server) == 1)
		return (1);
	while (tmp) {
		if (strncmp(tmp->name_team, buffer,
			    strlen(tmp->name_team)) == 0) {
			server->client[i].name_team = strdup(tmp->name_team);
			dprintf(fd, "%d\n", tmp->nb_player);
			dprintf(fd, "%d %d\n", server->width, server->height);
			return (1);
		}
		tmp = tmp->next;
	}
	dprintf(fd, "ko\n");
	return (0);
}

static void nb_player_connected(int i, server *server)
{
	team *tmp = server->team;

	while (tmp) {
		if (strcmp(server->client[i].name_team, tmp->name_team) == 0 ||
            strcmp(server->client[i].name_team, "graph") == 0) {
			tmp->nb_player--;
            server->fd_max--;
			return;
		}
		tmp = tmp->next;
	}
}

static void remove_client(server *server, int to_remove)
{
	memmove(server->client + to_remove,
			server->client + to_remove + 1,
			(server->actual - to_remove - 1) * sizeof(client));
	server->actual--;
}

static void disconnect_client(server *server, int i)
{
	printf("Client disconnected : %d\n", server->client[i].id);
	nb_player_connected(i, server);
	close(server->client[i].fd);
	remove_client(server, i);
    server->nb_player--;
}

void	manage_client(server *server, fd_set rdfs, char **buf)
{
	int i;
	int r;

	for (i = 0; i < server->actual; i++) {
		if (FD_ISSET(server->client[i].fd, &rdfs)) {
			memset(*buf, 0, 4096);
			r = read(server->client[i].fd, *buf, 4096);
			if (r == 0)
				disconnect_client(server, i);
			if (server->client[i].is_connected == 0) {
				if (first_cmd(*buf, server->client[i].fd, server, i) == 1) {
					server->client[i].is_connected = 1;
					bzero(*buf, 4096);
				}
			}
			else {
				if (strlen(*buf) != 0)
					server->client[i].exec =
						add_execution_list(server->client[i].exec, *buf);
			}
			break;
		}
	}
}
