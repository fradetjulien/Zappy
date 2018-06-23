#include "server.h"

void _fork(server *server, int i, char UNUSED **params)
{
	static int	id = 1;
	egg *egg;

	egg = malloc(sizeof(t_egg));
	egg->pos_x = server->client[i].posX;
	egg->pos_y = server->client[i].posY;
	egg->team_name = strdup(server->client[i].name_team);
	egg->id = id;
	egg->prev = NULL;
	egg->next = NULL;
	id++;
	add_egg(&server->eggs, egg);
	dprintf(server->client[i].fd, "ok\n");
}

void	add_egg(egg **eggs, egg *elem)
{
	egg	*tmp;

	if (*eggs == NULL) {
		*eggs = elem;
		return;
	}
	else {
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = elem;
		elem->prev = tmp;
	}
}

void	delete_egg(egg **eggs, egg *elem)
{
	egg *tmp;

	if (*eggs != NULL) {
		tmp = *eggs;
		while (tmp->next != NULL) {
			if (tmp->id == elem->id) {
				if (tmp->next && !tmp->prev) {
					tmp->next->prev = NULL;
					*eggs = tmp->next;
				}
				else if (tmp->prev && !tmp->next)
					tmp->prev->next = NULL;
				else if (tmp->prev && tmp->next) {
					tmp->next->prev = tmp->prev;
					tmp->prev->next = tmp->next;
				}
				return;
			}
		}
	}
}

void	new_client(server *server, egg *elem)
{
	struct sockaddr_in csin = {0};
	size_t	sinsize = sizeof csin;
	int	csock = accept(server->fd, (struct sockaddr *)&csin, (unsigned int *)&sinsize);
	server->fd_max = csock > server->fd_max ? csock : server->fd_max;
	client c = {csock, elem->team_name, 0, server->nb_player, 1, elem->pos_x,
		    elem->pos_y, NORTH, NULL, 1260};
	c.inventory = init_inventory();
	server->client[nb_player + 1] = c;
	server->actual++;
	server->nb_player++;
}
