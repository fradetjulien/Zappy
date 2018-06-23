//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// closeSocket.cpp
//

#include "../../include_client/client.hpp"
#include "../../include_client/exception.hpp"

int		Client::closeSocket()
{
	if (close(_fd) == -1) {
		throw MyError("");
	}
	_fd = -1;
	return (0);
}
