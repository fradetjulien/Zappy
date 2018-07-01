/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** draw the graphics
*/

#include "server.h"

int	draw_map(graphics *graph, server *server)
{
	int	rect_width = 0;
	int	rect_height = 0;
	SDL_Event	event;

	while (SDL_PollEvent(&event)) {
		if (get_events(event, &graph->window_width,
			&graph->window_height) == 1)
			return 1;
	}
	rect_width = (graph->window_width / server->width);
	rect_height = (graph->window_height / server->height);
	SDL_SetRenderDrawColor(graph->renderer, 0, 255, 0, 255);
	SDL_RenderClear(graph->renderer);
	draw_rects(graph, server, rect_width, rect_height);
	SDL_RenderPresent(graph->renderer);
	return 0;
}

void	draw_ressources(graphics *graph, server *server,
SDL_Rect pos, mappos map_pos)
{
	t_map	*tmp;
	client	*ctmp;
	int	i = 0;

	tmp = server->map;
	ctmp = server->client;
	while (tmp != NULL) {
		if (map_pos.x == tmp->node_pos->x &&
		map_pos.y == tmp->node_pos->y) {
			draw_stones(graph, tmp, pos);
		}
		tmp = tmp->next;
	}
	while (i++ != server->nb_player) {
		if (ctmp[i].posX == map_pos.x &&
			ctmp[i].posY == map_pos.y)
			draw_player(graph, pos);
	}
}

void	draw_stones(graphics *graph, t_map *tmp, SDL_Rect pos)
{
	draw_linemate(graph, tmp, pos);
	draw_deraumere(graph, tmp, pos);
	draw_sibur(graph, tmp, pos);
	draw_mendiane(graph, tmp, pos);
	draw_phiras(graph, tmp, pos);
	draw_thystame(graph, tmp, pos);
	draw_food(graph, tmp, pos);
}

void	draw_rects(graphics *graph, server *server, int rwidth, int rheight)
{
	int	nb_tiles = server->width * server->height;
	mappos	graph_pos = {0, 0};
	mappos	map_pos = {0, 0};
	mappos	rect_sizes = {rwidth, rheight};
	SDL_Rect	pos;

	pos.w = rwidth;
	pos.h = rheight;
	for (int i = 0; i < nb_tiles; i++) {
		pos.x = graph_pos.x;
		pos.y = graph_pos.y;
		//draw_tiles(graph, pos, map_pos, server);
		draw_ressources(graph, server, pos, map_pos);
		draw_player(graph, pos);
		set_rects_pos(&graph_pos, &map_pos, &rect_sizes, graph);
	}
}

void	set_rects_pos(mappos *graph_pos, mappos *map_pos, mappos *rect_sizes,
graphics *graph)
{
	if (graph_pos->x + rect_sizes->x > graph->window_width ||
	graph_pos->x + rect_sizes->x > graph->window_width - rect_sizes->x) {
		graph_pos->x = 0;
		map_pos->x = 0;
		graph_pos->y += rect_sizes->y;
		map_pos->y++;
	} else {
		graph_pos->x += rect_sizes->x;
		map_pos->x++;
	}
}
