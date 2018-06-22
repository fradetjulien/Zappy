//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// checkFDS.cpp
//

#include "Client.hpp"

void			whichStep()
{
	static int	isAlreadySend = 0;

	if (isAlreadySend == 2) {
		if (worldDimension() == 0)
			isAlreadySend = 3;
	}
	if (isAlreadySend == 1) {
		if (remainingPlaces() == 0)
			isAlreadySend = 2;
	}
	if (isAlreadySend == 0 && isWelcome() == 0) {
		contactServer();
		isAlreadySend = 1;
	}
}

int			Client::checkFDS()
{
	for (int i = 0; i < (_socket->fd + 1); i++) {
		if (FD_ISSET(_socket->fd, &_read)) {
			if (getInstruction() == -1)
				return (-1);
			whichStep();
		}
	}
	return (0);
}
