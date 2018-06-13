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

# define READ_SIZE 128

# define LOCALHOST	"127.0.0.1"

typedef struct			s_socket
{
	int			fd;
	struct sockaddr_in	s;
	socklen_t		len;
}t_socket;

typedef struct			s_client
{
	struct protoent		*protocol;
	char			*port;
	char			*team;
	char			*host;
	fd_set			*read;
	t_socket		*socket;
}t_client;

typedef struct			s_instructions
{
	int			(*_instructions[21])(t_client *c, char *instr);
}t_instructions;

/* Handle Client */
t_socket			*init_client(t_client *client);
void				free_client(t_client client);
void				help_client(char *binary);
int				launch_client(t_client *client);

/* Handle Arguments */
int				is_writearguments(t_client *client, char **av);
int				is_hostname(char *host);
int				is_port(char *port);

/* Handle Socket */
int				init_socket(t_client *client, const char *p);
int				close_socket(t_client *client);
int				connection_server(t_client *client);

/* Handle Instruction */
void				init_instructions(t_instructions *instructions);
char				*print_instruction(char *instruction_received);
char				*get_instruction(t_client *client);
int				read_instruction(t_client *client);
int				find_instruction(char *instruction);
int				execute_instruction(t_client *c, char *inst);
int				send_instruction(t_client *c, char *instruct);

/* Instructions */
int				forward(t_client *client, char *instruction);
int				right(t_client *client, char *instruction);
int				left(t_client *client, char *instruction);
int				look(t_client *client, char *instruction);
int				inventory(t_client *client, char *instruction);
int				bro(t_client *client, char *instruction);
int				broadcast(t_client *client , char *instruction);
int				cmd_connect(t_client *client, char *instruct);
int				cmd_fork(t_client *client, char *instruction);
int				eject(t_client *client, char *instruction);
int				take(t_client *client, char *instruction);
int				set(t_client *client, char *instruction);
int				incantation(t_client *client, char *instruct);
int				map_size(t_client *client, char *instruction);
int				content_tile(t_client *client, char *instruct);
int				content_map(t_client *client, char *instruct);
int				name_all_teams(t_client *c, char *instruct);
int				player_pos(t_client *client, char *instruction);
int				player_lvl(t_client *client, char *instruction);
int				player_inventory(t_client *c, char *instruct);
int				time_unit_request(t_client *c, char *instruct);
int				time_unit_modif(t_client *c, char *instruction);

/* Library */
char				*get_next_line(const int);

#endif /* !CLIENT_H_ */
