//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// contactServer.cpp
//

#include "../../include_client/client.hpp"

void		Client::contactServer()
{
	sendInstruction(_team.c_str());
	printInstruction(_answerReceived.c_str());
	printInstruction(_team.c_str());
    _isAlreadySend = 1;
}
