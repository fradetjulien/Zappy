//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// remainingPlaces.cpp
//

#include "../../include_client/client.hpp"
#include "../../include_client/exception.hpp"

int		Client::remainingPlaces()
{
	if (atoi(_answerReceived.c_str()) >= 1) {
		printInstruction(_answerReceived.c_str());
		return (0);
	}
	throw MyError("ici alors");
}
