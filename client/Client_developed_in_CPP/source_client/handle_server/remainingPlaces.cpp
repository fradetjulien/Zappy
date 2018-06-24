//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// remainingPlaces.cpp
//

#include "../../include_client/client.hpp"
#include "../../include_client/exception.hpp"

void	Client::remainingPlaces()
{
	if (atoi(_answerReceived.c_str()) >= 1) {
		printInstruction(_answerReceived.c_str());
		_isAlreadySend = 2;
		return ;
	}
	throw MyError("ici alors");
}
