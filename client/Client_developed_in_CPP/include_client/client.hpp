//
// EPITECH PROJECT, 2018
// PSU_zappy_2017
// File description:
// client.hpp
//

#ifndef CLIENT_HPP_
# define CLIENT_HPP_

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "Socket.hpp"

# define LOCALHOST	"127.0.0.1"

class				Client
{
private:
	struct protoent		*_protocol;
	std::string		_port;
	std::string		_team;
	std::string		_host;
	std::string		_answerReceived;
	int			_abscissa;
	int			_orderly;
	fd_set			_read;
	Socket			*_socket;
public:

/* Constructor & Destructor */
	Client(int ac, char **av);
	~Client();

/* Handle Client */
	int	launchClient();

/* Handle Arguments */
	int	isWriteArguments(char **av);
	int	isHostname(char *host);
	int	isPort(char *port);
	int	isWelcome();
	void	helpClient(char *binary);

/* Handle Socket */
	int	connectionServer();
	int	initSocket(const char *protocol);
	int	closeSocket();

/* Handle FD_Set */
	int	checkFDS();
	void	initFDS(int fd, fd_set *read, struct timeval *time);

/* Handle Server */
	void	contactServer();
	int	remainingPlaces();
	int	worldDimension();

/* Handle Instruction */
	int	getInstruction();
	void	sendInstruction();
	void	printInstruction();

};

#endif /* !CLIENT_HPP_ */
