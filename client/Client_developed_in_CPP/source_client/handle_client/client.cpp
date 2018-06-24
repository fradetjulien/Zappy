//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// client.cpp
//

#include "../../include_client/client.hpp"

Client::Client(int ac, char **av)
	: _abscissa(0), _orderly(0), _host("127.0.0.1")
{
	if (ac != 7 || isWriteArguments(av) != 0) {
		helpClient();
	}
	_isAlreadySend = 0;
	_ia = std::make_unique<Ia>();
	_step[0] = std::bind(&Client::contactServer, this);
	_step[1] = std::bind(&Client::remainingPlaces, this);
	_step[2] = std::bind(&Client::worldDimension, this);
	_step[3] = std::bind(&Client::execute_ia, this);
}

Client::~Client()
{
}

void	Client::execute_ia()
{

}