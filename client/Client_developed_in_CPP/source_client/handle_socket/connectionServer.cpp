//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// connectionServer.cpp
//

#include "../../include_client/client.hpp"
#include "../../include_client/exception.hpp"

int		Client::connectionServer()
{
	int	error = 0;

	if (initSocket("TCP") == -1) {
		std::cerr << "Can not initialize the connection"
			  << std::endl;
		return (-1);
	}
	_s.sin_family = AF_INET;
	_s.sin_addr.s_addr = inet_addr(_host.c_str());
	_s.sin_port = htons(atoi(_port.c_str()));
	error = connect(_fd, (const struct sockaddr *)&_s, sizeof(_s));
	if (error == -1) {
		closeSocket();
		throw MyError("Can not establish connection");
	}
	return (0);
}
