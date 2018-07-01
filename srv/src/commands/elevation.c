/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

void evolution_1(server *server, int i, int *incantation, t_map *map)
{
	if (server->client[i].level == 1) {
		if (map->rsrc->nb_linemate >= 1) {
			*incantation = 1;
			return;
		}
	}
}

void evolution_2(server *server, int i, int *incantation, t_map *map)
{
	if (server->client[i].level == 2) {
		if (map->rsrc->nb_linemate == 1 &&
		map->rsrc->nb_deraumere == 1 &&
		map->rsrc->nb_sibur == 1 &&
		map->rsrc->nb_phiras == 0 &&
		map->rsrc->nb_thystame == 0 &&
		map->rsrc->nb_mendiane == 0 &&
		check_players(server, i, 2) == 0) {
			*incantation = 1;
			return;
		}
	}
}

void evolution_3(server *server, int i, int *incantation, t_map *map)
{
	if (server->client[i].level == 3) {
		if (map->rsrc->nb_linemate == 2 &&
		map->rsrc->nb_sibur == 1 &&
		map->rsrc->nb_phiras == 2 &&
		map->rsrc->nb_thystame == 0 &&
		map->rsrc->nb_mendiane == 0 &&
		map->rsrc->nb_deraumere == 0 &&
		check_players(server, i, 2) == 0) {
			*incantation = 1;
			return;
		}
	}
}

void evolution_4(server *server, int i, int *incantation, t_map *map)
{
	if (server->client[i].level == 4) {
		if (map->rsrc->nb_linemate == 1 &&
		map->rsrc->nb_deraumere == 1 &&
		map->rsrc->nb_sibur == 2 &&
		map->rsrc->nb_phiras == 1 &&
		map->rsrc->nb_mendiane == 0 &&
		map->rsrc->nb_thystame == 0 &&
		check_players(server, i, 4) == 0) {
			*incantation = 1;
			return;
		}
	}
}

void evolution_5(server *server, int i, int *incantation, t_map *map)
{
	if (server->client[i].level == 5) {
		if (map->rsrc->nb_linemate == 1 &&
		map->rsrc->nb_deraumere == 2 &&
		map->rsrc->nb_sibur == 1 &&
		map->rsrc->nb_mendiane == 3 &&
		map->rsrc->nb_thystame == 0 &&
		map->rsrc->nb_phiras == 0 &&
		check_players(server, i, 4) == 0) {
			*incantation = 1;
			return;
		}
	}
}
