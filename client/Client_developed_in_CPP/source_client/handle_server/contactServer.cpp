//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// contactServer.cpp
//

#include "Client.hpp"

void		Client::contactServer()
{
	sendInstruction(_team);
	printInstruction(_answerReceived);
	printInstruction(_team);
}
