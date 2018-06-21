//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// client.cpp
//

#include "Client.hpp"

Client::Client(int ac, char **av)
	: _answerReceived(nullptr), _abscissa(0), _orderly(0), _host("127.0.0.1")
{
	if (ac != 7 || isWriteArguments(av) != 0) {
		helpClient(av[0]);
		return (-1);
	}
	return (0);
}

Client::~Client()
{
}
