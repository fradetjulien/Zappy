/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** help_client.c
*/

#include "client.h"

void		help_client(char *binary)
{
	printf("USAGE: %s -p port -n name -h machine\n", binary);
	printf("\tport\tis the port number\n");
	printf("\tname\tis the name of the team\n");
	printf("\tmachine\tis the name of the machine; ");
	printf("localhost by default\n");
}
