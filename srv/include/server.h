#ifndef SERVER_H_
#define SERVER_H

#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "ring_buffer.h"

# define HEIGHT 20
# define WIDTH 20

int     loop_server(int ac, char **av);
int	verification_args(char **av);
int	fill_port(char **av);
int     fill_width(char **av);
int     fill_height(char **av);
int     fill_nb_players(int ac, char **av);

typedef struct Client {
	char *name_team;
	int is_connected;
	int socket;
	int id;
	rbuffer *rb;
	struct Client *next;
}client;

typedef struct Team {
	char *name_team;
        int     nb_team;
        struct Team *next;
}team;

typedef struct Server {
        int fd;
        fd_set  server;
        int port;
	int width;
	int height;
	int nb_player;
        rbuffer *buffer;
	client *client;
        int     nbMax;
}server;

team    *add_list_team(char *name_team, team *list);
void    show_list_team(team *list);
team *fill_name_teams(int ac, char **av);
client *add_client(client *list);
void    init_client(client *, server *);
void show_client(client *list);
int     manage_cmd(server*, int fd);

typedef struct		s_node_pos
{
	int		x;
	int		y;
}			t_node_pos;

typedef struct		s_rsrc
{
	int		nb_linemate;
	int		nb_deraumere;
	int		nb_sibur;
	int		nb_mendiane;
	int		nb_phiras;
	int		nb_thystame;
	int		nb_food;
}			t_rsrc;

typedef struct			s_map
{
	struct s_node_pos	*node_pos;
	struct s_rsrc		*rsrc;
	struct s_map		*next;
}			t_map;


t_map	*init_pos(t_map *map, int xx, int yy);
t_map	*init_rsrc(t_map *map);
int	init_map();

int	set_under_twenty();
int	set_under_fifthteen();
int	set_under_ten();
int	set_under_seven();

int	my_random(int b);
int	my_range_random(int a, int b);


#endif /* SERVER_H_ */
