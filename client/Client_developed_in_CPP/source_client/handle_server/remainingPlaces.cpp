//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// remainingPlaces.cpp
//

#include "Client.hpp"

int		Client::remainingPlaces()
{
	if (atoi(_answerReceived) >= 1) {
		printInstruction();
		return (0);
	}
	return (-1);
}
