/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** set rsrc
*/

#include <time.h>
#include "../include/server.h"

int		set_under_twenty()
{
	int	k;
	
	if ((k = my_random(100)) < 50)
		return (my_range_random(1, 4));
	else
		return 0;
}

int		set_under_fifthteen()
{

	int	k;

	if ((k = my_random(100)) < 15)
		return (my_range_random(1, 3));
	else
		return 0;
}
