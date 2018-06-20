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

#define NORTH 0
#define EAST 1
#define WEST 2
#define SOUTH 3
#define UNUSED __attribute__((__unused__))

int     loop_server(int ac, char **av);
int	verification_args(char **av);
int	fill_port(char **av);
int     fill_width(char **av);
int     fill_height(char **av);
int     fill_nb_players(int ac, char **av);
int	fill_max_client(int ac, char **av);


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

typedef struct s_inventory {
    int		nb_linemate;
    int		nb_deraumere;
    int		nb_sibur;
    int		nb_mendiane;
    int		nb_phiras;
    int		nb_thystame;
    int		nb_food;
}t_inventory;

typedef struct Client {
	int fd;
	char *name_team;
	int is_connected;
	int id;
	int level;
	int posX;
	int posY;
	int orient;
	t_inventory *inventory;
	int time;
}client;

typedef struct Team {
		char *name_team;
        int     nb_player;
        struct Team *next;
}team;


typedef struct Server {
    int fd;
	int fd_max;
    int port;
	int width;
	int height;
	int nb_player;
	int max_client;
    rbuffer *buffer;
	client *client;
    int     nbMax;
	team *team;
	int actual;
	char *cmd[20];
	void (*command[20])(struct Server *, int, char **);
	t_map *map;
}server;

/*commands*/
void ppo(server *server, int i, char **paramss);
void sst(server *server, int i, char **params);
void bct(server *server, int i, char **params);
void broadcast(server *server, int i, char **params);
void connect_nbr(server *server, int i, char **params);
void eject(server *server, int i, char **params);
void _fork(server *server, int i, char **params);
void incantation(server *server, int i, char **params);
void inventory(server *server, int i, char **params);
void look(server *server, int i, char **params);
void msz(server *server, int i, char **params);
void mct(server *server, int i, char **params);
void forward(server *server, int i, char **params);
void left(server *server, int i, char **params);
void right(server *server, int i, char **params);
void pin(server *server, int i, char **params);
void plv(server *server, int i, char **params);
void sgt(server *server, int i, char **params);
void take(server *server, int i, char **params);
void tna(server *server, int i, char **params);
//

/*map*/
t_map	*init_pos(t_map *map, int xx, int yy);
t_map	*init_rsrc(t_map *map);
t_map	*init_map(server *server);
int	set_under_twenty();
int	set_under_fifthteen();
int	set_under_ten();
int	set_under_seven();

int	my_random(int b);
int	my_range_random(int a, int b);
//


team    *add_list_team(char *name_team, team *list, int ac, char **av);
void    show_list_team(team *list);
team *fill_name_teams(int ac, char **av);
client *add_client(client *list);
void    init_client(client *, server *);
void show_client(client *list);
int     manage_cmd(server*, int fd);
void	manage_client(server *server, fd_set rdfs);
void init_command(server *server);
void init_function_command(server *server);
char	**str_to_wordtab(char *str, char delimitor);
t_inventory *init_inventory();

#endif /* SERVER_H_ */
