/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <time.h>
#include "server.h"

int main(int ac, char **av)
{
	(void)ac;
	srand(time(NULL));
        if (loop_server(ac, av) == -1)
                return 84;
        return 0;
}
