/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** print_instruction.c
*/

#include "client.h"

char		*print_instruction(char *instruction_received, int state)
{
	if (instruction_received != NULL && state == 1) {
		printf("%s\n", instruction_received);
	}
	else if (instruction_received != NULL && state == 0) {
		printf("%s\n", instruction_received);
	}
	return (NULL);
}
