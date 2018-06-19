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
	t_map	*tmp;

	new = NULL;
	if ((new = malloc(sizeof(t_map))) == NULL)
		return NULL;
	if ((new->node_pos = malloc(sizeof(t_node_pos))) == NULL)
		return NULL;
	new->node_pos->x = xx;
	new->node_pos->y = yy;
        if (map == NULL)
		return (new);
	else {
		tmp = map;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		return (tmp);
	}
}

t_map		*init_rsrc(t_map *map)
{
	if ((map->rsrc = malloc(sizeof(t_rsrc))) == NULL)
		return NULL;
	map->rsrc->nb_linemate = set_under_twenty();
	map->rsrc->nb_deraumere = set_under_twenty();
	map->rsrc->nb_sibur = set_under_fifthteen();
	map->rsrc->nb_mendiane = set_under_ten();
	map->rsrc->nb_phiras = set_under_ten();
	map->rsrc->nb_thystame = set_under_seven();
	map->rsrc->nb_food = my_range_random(1, 3);
	return (map);
}

int		init_map()
{
	int	xx;
	int	yy;
	t_map	*map;

	xx = -1;
	map = NULL;
	srand(time(NULL));
	while (++xx < HEIGHT) {
		yy = -1;
	        while (++yy < WIDTH) {
			if ((map = init_pos(map, xx, yy)) == NULL)
				return 84;
			//printf("x = %d y = %d", map->node_pos->x, map->node_pos->y);
			if ((map = init_rsrc(map)) == NULL)
				return 84;
			//printf("Bloc en position %d, %d \n", xx, yy);
			//printf("Linemate = %d\n", map->rsrc->nb_linemate);
			//printf("Deraumere = %d\n", map->rsrc->nb_deraumere);
			//printf("Sibur = %d\n", map->rsrc->nb_sibur);
			//printf("Mendiane = %d\n", map->rsrc->nb_mendiane);
			//printf("Phiras = %d\n", map->rsrc->nb_phiras);
			printf("food = %d    ", map->rsrc->nb_food);
			printf("Thystame = %d\n", map->rsrc->nb_thystame);
		}
		printf("---------------------------------------\n");
	}
	return 0;
}

void	main()
{
	init_map();
}
