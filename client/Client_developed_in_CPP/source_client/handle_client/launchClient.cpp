//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// launchClient.cpp
//

#include "../../include_client/client.hpp"

int			Client::launchClient()
{
	int		fdMax = _fd + 1;
	int		launcher = 1;
	struct timeval	time;

	while (launcher) {
		initFDS(&_read, &time);
		if (select(fdMax, &_read, nullptr, nullptr, &time) == -1) {
			std::cerr << "Select error" << std::endl;
			return (-1);
		}
		checkFDS();
	}
	return (0);
}
