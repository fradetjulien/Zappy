/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** read_instruction.c
*/

#include "client.h"

int		read_instruction(t_client *client)
{
	int	error = 0;
	char	instruction[255];

	error = read(, instruction, 255);
	if (error == -1) {
		printf("Failure to read the instruction\n");
		return (-1);
	}
	else if (error == 0) {
		printf("Client already closed\n");
		return (-1);
	}
	instruction[error] = '\0';
	execute_instruction(client, instruction);
	return (0);
}
