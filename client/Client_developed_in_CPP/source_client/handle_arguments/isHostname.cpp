//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// isHostname.cpp
//

#include "Client.hpp"

int		Client::isHostname(char *host)
{
	int	i = 0;

	if (host == NULL) {
		return (-1);
	}
	while (host && host[i] != '\0') {
		if ((host[i] < 48 || host[i] > 57) && host[i] != '.') {
			return (-1);
		}
		i++;
	}
	return (0);
}
