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
#include <cstdlib>
#include <cstring>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "socket.hpp"

# define LOCALHOST	"127.0.0.1"

class				Client
{
private:
	struct protoent		*_protocol;
	std::string		_port;
	std::string		_team;
	std::string		_answerReceived;
	int			_abscissa;
	int			_orderly;
	std::string		_host;
	fd_set			_read;
    int			_fd;
    struct sockaddr_in	_s;
    socklen_t		_len;
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
	void	helpClient();

/* Handle Socket */
	int	connectionServer();
	int	initSocket(const char *protocol);
	int	closeSocket();

/* Handle FD_Set */
    void whichStep();
	int	checkFDS();
	void	initFDS(fd_set *read, struct timeval *time);

/* Handle Server */
	void	contactServer();
	int	remainingPlaces();
	int	worldDimension();

/* Handle Instruction */
	int	getInstruction();
	void	sendInstruction();
	void	printInstruction(const char *);

};

#endif /* !CLIENT_HPP_ */
