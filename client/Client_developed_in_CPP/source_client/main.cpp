//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// main.cpp
//

#include "Client.hpp"

int		main(int ac, char **av)
{
	Client	newClient(ac, av);

	if (connectionServer() == -1)
		return (-1);
	if (launchClient() == -1)
		return (-1);
	return (0);
}
