/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** find_instruction.c
*/

//#include "client.h"

void	init_realInstructions_one(char **realInstructions)
{
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
}

void	init_realInstructions_two(char **realInstructions)
{
	realInstructions[11] = "incantation";
	realInstructions[12] = "msz";
	realInstructions[13] = "bct";
	realInstructions[14] = "mct";
	realInstructions[15] = "tna";
	realInstructions[16] = "ppo";
	realInstructions[17] = "plv";
	realInstructions[18] = "pin";
	realInstructions[19] = "sgt";
	realInstructions[20] = "sst T";
}

int		find_instruction(char *instruction)
{
	int	position = 0;
	int	i = 0;
	int	j = 0;
	char	*realInstructions[21];

	init_realInstructions_one(realInstructions);
	init_realInstructions_two(realInstructions);
	while (position < 10 && (strcmp(instruction, realInstructions[position])) != 0)
		position++;
	if (position > 9)
		return (-1);
	return (position);
}
