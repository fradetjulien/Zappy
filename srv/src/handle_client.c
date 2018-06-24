/*
** EPITECH PROJECT, 2018
** handle_client
** File description:
** handle_client
*/

#include "server.h"
#include "ring_buffer.h"


static int first_cmd(char *buffer, int fd, server *server, int i)
{
    team *tmp = server->team;

    while (tmp) {
        if (strncmp(tmp->name_team, buffer,
                    strlen(tmp->name_team)) == 0) {
            server->client[i].name_team = strdup(tmp->name_team);
            tmp->nb_player--;
            dprintf(fd, "%d\n", tmp->nb_player);
            dprintf(fd, "%d %d\n", server->width, server->height);
            return (1);
        }
        tmp = tmp->next;
    }
    dprintf(fd, "ko\n");
    return (0);
}

void	manage_client(server *server, fd_set rdfs, char **buf)
{
	int i;
	int r;

    for (i = 0; i < server->actual; i++) {
        if (FD_ISSET(server->client[i].fd, &rdfs)) {
            memset(*buf, 0, 4096);
            r = read(server->client[i].fd, *buf, 4096);
            if (r == 0) {
                printf("Client disconnected : %d\n", server->client[i].id);
                close(server->client[i].fd);
                server->actual--;
            }
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
