/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** set rsrc
*/

#include "../include/server.h"

int		set_under_ten()
{
	int	k;
	
	if ((k = my_random(100)) < 10)
		return (my_range_random(1, 2));
	else
		return 0;
}

int		set_under_seven()
{
	int	k;
	
	if ((k = my_random(100)) < 7)
		return 1;
	else
		return 0;
}
