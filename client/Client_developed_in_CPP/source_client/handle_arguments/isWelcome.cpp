//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// isWelcome.cpp
//

#include "Client.hpp"

int		Client::isWelcome()
{
	if (_answerReceived == nullptr) {
		return (-1);
	}
	else if (strcmp(_answerReceived, "WELCOME") != 0) {
		return (-1);
	}
	else {
		return (0);
	}
	return (-1);
}
