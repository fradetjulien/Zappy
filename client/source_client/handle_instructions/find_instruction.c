/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** find_instruction.c
*/

#include "client.h"

void	init_realinstructions(char **real_instructions)
{
	real_instructions[0] = "forward\n";
	real_instructions[1] = "right\n";
	real_instructions[2] = "left\n";
	real_instructions[3] = "look\n";
	real_instructions[4] = "inventory\n";
	real_instructions[5] = "broadcast text\n";
	real_instructions[6] = "cmd_connect\n";
	real_instructions[7] = "cmd_fork\n";
	real_instructions[8] = "eject\n";
	real_instructions[9] = "take oject\n";
	real_instructions[10] = "set oject\n";
}

void	init_realinstructions2(char **real_instructions)
{
	real_instructions[11] = "incantation";
	real_instructions[12] = "msz";
	real_instructions[13] = "bct";
	real_instructions[14] = "mct";
	real_instructions[15] = "tna";
	real_instructions[16] = "ppo";
	real_instructions[17] = "plv";
	real_instructions[18] = "pin";
	real_instructions[19] = "sgt";
	real_instructions[20] = "sst ";
}

int		find_instruction(char *instruction)
{
	int	position = 0;
	char	*realinstructions[21];

	init_realinstructions(realinstructions);
	init_realinstructions2(realinstructions);
	while (position < 21 && (strncmp(instruction,
	realinstructions[position], strlen(realinstructions[position])) != 0))
		position++;
	if (position > 20)
		return (-1);
	return (position);
}
