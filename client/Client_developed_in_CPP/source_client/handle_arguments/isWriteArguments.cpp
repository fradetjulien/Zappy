//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// isWriteArguments.cpp
//


#include "../../include_client/client.hpp"

int		Client::isWriteArguments(char **av)
{
	if ((strcmp(av[1], "-p") != 0) ||
	(strcmp(av[3], "-n") != 0) ||
	(strcmp(av[5], "-h") != 0)) {
		std::cout << "oui\n";
                return (-1);
        }
	else if (isHostname(av[6]) != 0 || isPort(av[2]) != 0) {
		return (-1);
	}
	else {
		_port = av[2];
		_team = av[4];
		_host = av[6];
        }
        return (0);
}
