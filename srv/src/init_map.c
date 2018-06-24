/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** init map
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/server.h"

t_map		*init_pos(t_map *map, int xx, int yy)
{
	t_map	*new;
	t_map	*tmp = NULL;

	new = NULL;
	if ((new = malloc(sizeof(t_map))) == NULL)
		return NULL;
	if ((new->node_pos = malloc(sizeof(t_node_pos))) == NULL)
		return NULL;
	new->node_pos->x = xx;
	new->node_pos->y = yy;
	new->next = NULL;
	if (map == NULL)
		return (new);
	else {
		tmp = map;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		return (map);
	}
}

t_map		*init_rsrc(t_map *map)
{
	if ((map->rsrc = malloc(sizeof(t_rsrc))) == NULL)
		return NULL;
	map->rsrc->nb_linemate = set_under_twenty();
	map->rsrc->nb_deraumere = set_under_twenty();
	map->rsrc->nb_sibur = set_under_fifthteen();
	map->rsrc->nb_mendiane = set_under_fifthteen();
	map->rsrc->nb_phiras = set_under_ten();
	map->rsrc->nb_thystame = set_under_ten();
	map->rsrc->nb_food = my_range_random(1, 3);
	return (map);
}

t_map		*init_map(server *server)
{
	int	xx;
	int	yy;
	t_map	*map;

	xx = -1;
	map = NULL;
	while (++xx < server->height) {
		yy = -1;
		while (++yy < server->width) {
			if ((map = init_pos(map, xx, yy)) == NULL)
				return NULL;
		}
	}
	t_map *tmp = map;
	while (tmp) {
		tmp = init_rsrc(tmp);
		tmp = tmp->next;
	}
	return map;
}
