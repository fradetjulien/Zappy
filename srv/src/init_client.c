/*
** EPITECH PROJECT, 2018
** init_client
** File description:
** init_client
*/

#include "server.h"
#include "ring_buffer.h"

void	init_client(client *client, server *server)
{
	server->nb_player++;
        client->id = server->nb_player;
        client->is_connected = 0;
        client->name_team = NULL;
	client->rb = ring_buffer_init();
}

client *add_client(client *list)
{
	client	*new;
        client	*tmp;

        if ((new = malloc(sizeof(struct Client))) == NULL)
	        return (NULL);
        new->next = NULL;
	if (list == NULL)
                return (new);
        else {
                tmp = list;
                while (tmp->next != NULL)
			tmp = tmp->next;
                tmp->next = new;
                return (list);
        }
}

void show_client(client *list)
{
	client *tmp = list;

	while (tmp) {
		printf("name of the team = %s\n", tmp->name_team);
		printf("is_connected = %d\n", tmp->is_connected);
		tmp = tmp->next;
	}
}
