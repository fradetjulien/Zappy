/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

void init_command(server *server)
{
	server->cmd[0] = "Forward";
	server->cmd[1] = "Right";
	server->cmd[2] = "Left";
	server->cmd[3] = "Look";
	server->cmd[4] = "Inventory";
	server->cmd[5] = "Broadcast";
	server->cmd[6] = "Connect_nbr";
	server->cmd[7] = "Fork";
	server->cmd[8] = "Eject";
	server->cmd[9] = "Take";
	server->cmd[10] = "Incantation";
	server->cmd[11] = "Set";
	server->cmd[12] = "msz";
	server->cmd[13] = "bct";
	server->cmd[14] = "mct";
	server->cmd[15] = "tna";
	server->cmd[16] = "ppo";
	server->cmd[17] = "plv";
	server->cmd[18] = "pin";
	server->cmd[19] = "sgt";
	server->cmd[20] = "sst";
	server->cmd[21] = NULL;
}

void init_function_command(server *server)
{
	server->command[0] = &forward;
	server->command[1] = &right;
	server->command[2] = &left;
	server->command[3] = &look;
	server->command[4] = &inventory;
	server->command[5] = &broadcast;
	server->command[6] = &connect_nbr;
	server->command[7] = &_fork;
	server->command[8] = &eject;
	server->command[9] = &take;
	server->command[10] = &incantation;
	server->command[11] = &set;
	server->command[12] = &msz;
	server->command[13] = &bct;
	server->command[14] = &mct;
	server->command[15] = &tna;
	server->command[16] = &ppo;
	server->command[17] = &plv;
	server->command[18] = &pin;
	server->command[19] = &sgt;
	server->command[20] = &sst;
	server->command[21] = NULL;
}
