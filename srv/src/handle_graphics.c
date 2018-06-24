/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Inits the use of SDL
*/

#include "server.h"

int	init_sdl(graphics *graph)
{
	SDL_Init(SDL_INIT_VIDEO);
	graph->window_width = 1900;
	graph->window_height = 995;
	graph->window = SDL_CreateWindow("Zappy", 0, 0, graph->window_width,
	graph->window_height, SDL_WINDOW_RESIZABLE);
	graph->renderer = SDL_CreateRenderer(graph->window, -1, 0);
	return 0;
}

int	destroy_sdl_elements(graphics *graph)
{
	SDL_DestroyWindow(graph->window);
	SDL_DestroyRenderer(graph->renderer);
	SDL_Quit();
	return 0;
}

int	get_events(SDL_Event event, int *w, int *h)
{
	if (event.type == SDL_WINDOWEVENT) {
		if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
			*w = event.window.data1;
			*h = event.window.data2;
		}
	}
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE &&
		event.key.state == SDL_PRESSED) {
			return 1;
		}
	}
	return 0;
}
