/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** draw player and a stone on the sdl
*/

#include "server.h"

void	draw_thystame(graphics *graph, t_map *tmp, SDL_Rect pos)
{
	SDL_Rect	tmp_pos;
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (tmp->rsrc->nb_thystame != 0) {
		tmp_pos.w = pos.w / 5;
		tmp_pos.h = pos.h / 5;
		tmp_pos.x = pos.x + (2 * tmp_pos.w);
		tmp_pos.y = pos.y + (2 * tmp_pos.h);
		surface = SDL_CreateRGBSurface(0, tmp_pos.w,
		tmp_pos.h, 32, 0, 0, 0, 0);
		SDL_SetRenderDrawColor(graph->renderer, 128, 0, 128, 255);
		SDL_RenderDrawRect(graph->renderer, &tmp_pos);
		SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format,
		128, 0, 128, 255));
		texture = SDL_CreateTextureFromSurface(graph->renderer,
		surface);
		SDL_RenderCopy(graph->renderer, texture, NULL, &tmp_pos);
	}
}

void	draw_food(graphics *graph, t_map *tmp, SDL_Rect pos)
{
	SDL_Rect	tmp_pos;
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (tmp->rsrc->nb_food != 0) {
		tmp_pos.w = pos.w / 5;
		tmp_pos.h = pos.h / 5;
		tmp_pos.x = pos.x + (4 * tmp_pos.w) + 1;
		tmp_pos.y = pos.y + 1;
		surface = SDL_CreateRGBSurface(0, tmp_pos.w, tmp_pos.h,
		32, 0, 0, 0, 0);
		SDL_SetRenderDrawColor(graph->renderer, 255, 0, 0, 255);
		SDL_RenderDrawRect(graph->renderer, &tmp_pos);
		SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format,
		255, 0, 0, 255));
		texture = SDL_CreateTextureFromSurface(graph->renderer,
		surface);
		SDL_RenderCopy(graph->renderer, texture, NULL, &tmp_pos);
	}
}

void	draw_player(graphics *graph, SDL_Rect pos)
{
	SDL_Rect	tmp_pos;
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	tmp_pos.w = pos.w / 6;
	tmp_pos.h = pos.h / 4;
	tmp_pos.x = pos.x + (4 * tmp_pos.w) + 1;
	tmp_pos.y = pos.y + (2 * tmp_pos.h);
	surface = SDL_CreateRGBSurface(0, tmp_pos.w, tmp_pos.h,
	32, 0, 0, 0, 0);
	SDL_SetRenderDrawColor(graph->renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(graph->renderer, &tmp_pos);
	SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format,
	0, 0, 0, 255));
	texture = SDL_CreateTextureFromSurface(graph->renderer,
	surface);
	SDL_RenderCopy(graph->renderer, texture, NULL, &tmp_pos);
}

/*void	draw_tiles(graphics *graph, SDL_Rect pos,
mappos map_pos, server *server)
{
	int	i = 0;
	client	*tmp;
	int	is_incant = 0;
	(void)map_pos;
	(void)server;
	tmp = server->client;
	while (i++ != server->nb_player) {
	 	exec_tmp = tmp[i].exec;
	 	while (exec_tmp != NULL) {
	 		if (strcmp(exec_tmp->cmd, "Incantation\n") == 0 &&
			(tmp->posX == map_pos.x && tmp->posY == map_pos.y))
	 		is_incant = draw_incant(graph, pos);
	 		exec_tmp = exec_tmp->next;
	 	}
	 }
	if (is_incant == 0) {
		SDL_SetRenderDrawColor(graph->renderer, 0, 0, 0, 0);
		SDL_RenderDrawRect(graph->renderer, &pos);
	}
}*/

/* int	draw_incant(graphics *graph, SDL_Rect pos) */
/* { */
/* 	SDL_Surface	*surface; */
/* 	SDL_Texture	*texture; */

/* 	surface = SDL_CreateRGBSurface(0, pos.w, pos.h, 32, 0, 0, 0, 0); */
/* 	SDL_FillRect(surface, NULL, */
/* 	SDL_MapRGBA(surface->format, 0, 0, 0 , 255)); */
/* 	SDL_SetRenderDrawColor(graph->renderer, 0, 0, 255, 255); */
/* 	SDL_RenderDrawRect(graph->renderer, &pos); */
/* 	texture = SDL_CreateTextureFromSurface(graph->renderer, surface); */
/* 	SDL_RenderCopy(graph->renderer, texture, NULL, &pos); */
/* 	return 1; */
/* } */
