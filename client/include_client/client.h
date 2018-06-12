/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client.h
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <arpa/inet.h>

# define LOCALHOST	"127.0.0.1"

typedef struct			s_socket
{
	int			fd;
	struct sockaddr_in	s;
	socklen_t		len;
}				t_socket;

typedef struct			s_client
{
	struct protoent		*protocol;
	char			*port;
	char			*team;
	char			*host;
	fd_set			*read;
	t_socket		*socket;
}				t_client;

typedef struct			s_instructions
{
	int			(*_instructions[21])(t_client *client, char *instruction);
}				t_instructions;

/* Gestion Client */
t_socket			*init_client(t_client *client);
void				free_client(t_client client);
void				help_client(char *binary);
int				launch_client(t_client *client);

/* Gestion Arguments */
int				isWriteArguments(t_client *client, char **av);
int				isHostname(char *host);
int				isPort(char *port);

/* Gestion Socket */
int				init_socket(t_client *client, const char *protocol);
int				close_socket(t_client *client);
int				connection_serveur(t_client *client);

/* Gestion Instruction */
void				init_instructions(t_instructions *instructions);
int				read_instruction(t_client *client);
int				find_instruction(char *instruction);
int				execute_instruction(t_client *client, char *instruction);

#endif /* !CLIENT_H_ */
