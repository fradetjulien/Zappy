/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** help_client.c
*/

#include "client.h"

void		help_client(char *binary)
{
	printf("USAGE: %s -p port -n name -h machine\n"
	       "\tport\tis the port number\n"
	       "\tname\tis the name of the team\n"
	       "\tmachine\tis the name of the machine; "
	       "localhost by default\n", binary);
}
