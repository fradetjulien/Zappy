//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// isWelcome.cpp
//

#include "../../include_client/client.hpp"

int		Client::isWelcome()
{
	if (_answerReceived.empty()) {
		return (-1);
	}
	else if (_answerReceived == "WELCOME") {
		return (-1);
	}
	else {
		return (0);
	}
}
