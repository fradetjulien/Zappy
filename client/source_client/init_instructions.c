/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** init_instructions.c
*/

#include "client.h"

void		init_instructions(t_instructions *instru)
{
	instru->_instructions = 
		{
			&forward, &right, &left,
			&look, &inventory, &bro,
			&broadcast, &connect, &fork,
			&eject, &take, &set, &incantation,
			&map_size, &content_tile, &content_map,
			&name_all_teams, &player_pos, &player_lvl,
			&player_inventory, &time_unit_request, &time_unit_modif
		}
}
