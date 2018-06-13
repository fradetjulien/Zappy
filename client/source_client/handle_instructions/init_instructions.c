/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** init_instructions.c
*/

#include "client.h"

void		following_init(t_instructions *instru)
{
	instru->_instructions[17] = &player_pos;
	instru->_instructions[18] = &player_lvl;
	instru->_instructions[19] = &player_inventory;
	instru->_instructions[20] = &time_unit_request;
	instru->_instructions[21] = &time_unit_modif;
}

void		init_instructions(t_instructions *instru)
{
	instru->_instructions[0] = &forward;
	instru->_instructions[1] = &right;
	instru->_instructions[2] = &left;
	instru->_instructions[3] = &look;
	instru->_instructions[4] = &inventory;
	instru->_instructions[5] = &broadcast;
	instru->_instructions[6] = &cmd_connect;
	instru->_instructions[7] = &cmd_fork;
	instru->_instructions[8] = &eject;
	instru->_instructions[10] = &take;
	instru->_instructions[11] = &set;
	instru->_instructions[12] = &incantation;
	instru->_instructions[13] = &map_size;
	instru->_instructions[14] = &content_tile;
	instru->_instructions[15] = &content_map;
	instru->_instructions[16] = &name_all_teams;
	following_init(instru);
}
