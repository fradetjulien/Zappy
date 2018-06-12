/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** execute_instruction.c
*/

#include "client.h"

int			execute_instruction(t_client *client, char *instruction)
{
	t_instructions	instruct;
	int		this = 0;

	init_instructions(&instruct, client, instruction);
	this = find_instruction(instruction);
	if (this == -1)
		return (-1);
	instruct._instructions[this](client, instruction);
	return (0);
}
