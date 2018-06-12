/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** find_instruction.c
*/

#include "client.h"

int		find_instruction(char *instruction)
{
	int	position = 0;
	char	*realInstructions[12];

	realInstructions[0] = "forward\n";
	realInstructions[1] = "right\n";
	realInstructions[2] = "left\n";
	realInstructions[3] = "look\n";
	realInstructions[4] = "inventory\n";
	realInstructions[5] = "broadcast text\n";
	realInstructions[6] = "connect_nbr\n";
	realInstructions[7] = "fork\n";
	realInstructions[8] = "eject\n";
	realInstructions[9] = "take oject\n";
	realInstructions[10] = "set oject\n";
	realInstructions[11] = "incantation";
	while (position < 10 && (strcmp(instruction, realInstructions[position])) != 0)
		position++;
	if (position > 9)
		return (-1);
	return (position);
}
