//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// isPort.cpp
//

#include "../../include_client/client.hpp"

int		Client::isPort(char *port)
{
	int	i = 0;

	if (port == nullptr) {
		return (-1);
	}
	while (port && port[i] != '\0') {
		if (port[i] < 48 || port[i] > 57) {
			return (-1);
		}
		i++;
	}
	return (0);
}
