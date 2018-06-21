//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// launchClient.cpp
//

#include "Client.hpp"

int			Client::launchClient()
{
	int		fdMax = _socket->fd + 1;
	int		launcher = 1;
	struct timeval	time;

	while (launcher) {
		initFDS(_socket->fd, &_read, &time);
		if (select(fdMax, &_read, nullptr, nullptr, &time) == -1) {
			std::cerr << "Select error" << std::endl;
			return (-1);
		}
		if (checkFDS() == -1)
			return (-1);
	}
	return (0);
}
