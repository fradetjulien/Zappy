/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** print_instruction.c
*/

#include "client.h"

char		*print_instruction(char *instruction_received)
{
	if (instruction_received == NULL) {
		printf("--> %s\n", instruction_received);
		free(instruction_received);
	}
	return (NULL);
}
