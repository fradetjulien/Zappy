//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// checkFDS.cpp
//

#include "../../include_client/client.hpp"

void			Client::whichStep()
{
	static int	isAlreadySend = 0;

	std::cout << "received : " << _answerReceived << std::endl;
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
	for (int i = 0; i < (_fd + 1); i++) {
		if (FD_ISSET(_fd, &_read)) {
			getInstruction();
			whichStep();
		}
	}
	return (0);
}
