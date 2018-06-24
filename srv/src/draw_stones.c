/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** draw different stones
*/

#include "server.h"

void	draw_linemate(graphics *graph, t_map *tmp, SDL_Rect pos)
{
	SDL_Rect	tmp_pos;
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (tmp->rsrc->nb_linemate != 0) {
		tmp_pos.x = pos.x + 1;
		tmp_pos.y = pos.y + 1;
		tmp_pos.w = pos.w / 5;
		tmp_pos.h = pos.h / 5;
		surface = SDL_CreateRGBSurface(0, tmp_pos.w, tmp_pos.h,
		32, 0, 0, 0, 0);
		SDL_SetRenderDrawColor(graph->renderer, 255, 255, 0, 255);
		SDL_RenderDrawRect(graph->renderer, &tmp_pos);
		SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 255,
		255, 0, 255));
		texture = SDL_CreateTextureFromSurface(graph->renderer,
		surface);
		SDL_RenderCopy(graph->renderer, texture, NULL, &tmp_pos);
	}
}

void	draw_deraumere(graphics *graph, t_map *tmp, SDL_Rect pos)
{
	SDL_Rect	tmp_pos;
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (tmp->rsrc->nb_deraumere != 0) {
		tmp_pos.w = pos.w / 5;
		tmp_pos.h = pos.h / 5;
		tmp_pos.x = pos.x + 1;
		tmp_pos.y = pos.y + (2 * tmp_pos.h);
		surface = SDL_CreateRGBSurface(0, tmp_pos.w, tmp_pos.h,
		32, 0, 0, 0, 0);
		SDL_SetRenderDrawColor(graph->renderer, 0, 0, 255, 255);
		SDL_RenderDrawRect(graph->renderer, &tmp_pos);
		SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format,
		0, 0, 255, 255));
		texture = SDL_CreateTextureFromSurface(graph->renderer,
		surface);
		SDL_RenderCopy(graph->renderer, texture, NULL, &tmp_pos);
	}
}

void	draw_sibur(graphics *graph, t_map *tmp, SDL_Rect pos)
{
	SDL_Rect	tmp_pos;
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (tmp->rsrc->nb_sibur != 0) {
		tmp_pos.w = pos.w / 5;
		tmp_pos.h = pos.h / 5;
		tmp_pos.x = pos.x + 1;
		tmp_pos.y = pos.y + (4 * tmp_pos.h) + 3;
		surface = SDL_CreateRGBSurface(0, tmp_pos.w, tmp_pos.h,
		32, 0, 0, 0, 0);
		SDL_SetRenderDrawColor(graph->renderer, 255, 0, 255, 255);
		SDL_RenderDrawRect(graph->renderer, &tmp_pos);
		SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format,
		255, 0, 255, 255));
		texture = SDL_CreateTextureFromSurface(graph->renderer,
		surface);
		SDL_RenderCopy(graph->renderer, texture, NULL, &tmp_pos);
	}
}

void	draw_mendiane(graphics *graph, t_map *tmp, SDL_Rect pos)
{
	SDL_Rect	tmp_pos;
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (tmp->rsrc->nb_mendiane != 0) {
		tmp_pos.w = pos.w / 5;
		tmp_pos.h = pos.h / 5;
		tmp_pos.x = pos.x + (2 * tmp_pos.w);
		tmp_pos.y = pos.y + (4 * tmp_pos.h) + 3;
		surface = SDL_CreateRGBSurface(0, tmp_pos.w, tmp_pos.h,
		32, 0, 0, 0, 0);
		SDL_SetRenderDrawColor(graph->renderer, 192, 192, 192, 255);
		SDL_RenderDrawRect(graph->renderer, &tmp_pos);
		SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format,
		192, 192, 192, 255));
		texture = SDL_CreateTextureFromSurface(graph->renderer,
		surface);
		SDL_RenderCopy(graph->renderer, texture, NULL, &tmp_pos);
	}
}

void	draw_phiras(graphics *graph, t_map *tmp, SDL_Rect pos)
{
	SDL_Rect	tmp_pos;
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (tmp->rsrc->nb_phiras != 0) {
		tmp_pos.w = pos.w / 5;
		tmp_pos.h = pos.h / 5;
		tmp_pos.x = pos.x + (2 * tmp_pos.w);
		tmp_pos.y = pos.y + 1;
		surface = SDL_CreateRGBSurface(0, tmp_pos.w, tmp_pos.h,
		32, 0, 0, 0, 0);
		SDL_SetRenderDrawColor(graph->renderer, 255, 255, 255, 255);
		SDL_RenderDrawRect(graph->renderer, &tmp_pos);
		SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format,
		255, 255, 255, 255));
		texture = SDL_CreateTextureFromSurface(graph->renderer,
		surface);
		SDL_RenderCopy(graph->renderer, texture, NULL, &tmp_pos);
	}
}
