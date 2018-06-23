//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// initSocket.cpp
//

#include "../../include_client/client.hpp"
#include "../../include_client/exception.hpp"

int		Client::initSocket(const char *protocol)
{
	_protocol = getprotobyname(protocol);
	if (_protocol == nullptr)
		throw MyError("");
	_fd = socket(AF_INET, SOCK_STREAM,
	_protocol->p_proto);
	if (_fd == -1)
		throw MyError("");
	return (0);
}
