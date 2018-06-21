/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** utils
*/

#include <stdlib.h>
#include "../include/server.h"

int	my_range_random(int a, int b)
{
	return (rand() % (b - a) + a);
}

int	my_random(int b)
{
	return (rand() % b);
}
