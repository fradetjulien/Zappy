//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// contactServer.cpp
//

#include "../../include_client/client.hpp"

void		Client::contactServer()
{
	sendInstruction();
	printInstruction(_answerReceived.c_str());
	printInstruction(_team.c_str());
}
