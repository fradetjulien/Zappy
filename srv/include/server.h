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
#include <time.h>

#define UNUSED __attribute__((__unused__))

int     loop_server(int ac, char **av);
int	verification_args(char **av);
int	fill_port(char **av);
int     fill_width(char **av);
int     fill_height(char **av);
int     fill_nb_players(int ac, char **av);
int	fill_max_client(int ac, char **av);
int fill_frequency(int ac, char **av);

enum ORIENT {
    NORTH,
    EAST,
    WEST,
    SOUTH
};

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


typedef struct t_execution {
    char *cmd;
    double time;
    struct t_execution *next;
}s_execution;

typedef struct Client {
	int fd;
	char *name_team;
	int is_connected;
	int id;
	int level;
	int posX;
	int posY;
	int orient;
	t_rsrc *inventory;
	int time;
	s_execution *exec;
}client;

typedef struct Team {
		char *name_team;
        int     nb_player;
        struct Team *next;
}team;

typedef struct		s_look
{
	const char 			*str;
	struct s_look	*next;
}					t_look;

typedef struct Egg {
        int             pos_x;
        int             pos_y;
        char            *team_name;
        int             id;
        struct Egg      *prev;
        struct Egg      *next;
}egg;

typedef struct Server {
    int fd;
	int fd_max;
    int port;
	int width;
	int height;
	int nb_player;
	int frequency;
	client *client;
    int     nbMax;
	team *team;
	int actual;
	char *cmd[21];
	int (*command[21])(struct Server *, int, char **);
	t_map *map;
	t_look *look;
	egg *eggs;
}server;

int execute_cmd(server *);

/*commands*/
int ppo(server *server, int i, char **params);
int sst(server *server, int i, char **params);
int bct(server *server, int i, char **params);
int broadcast(server *server, int i, char **params);
int connect_nbr(server *server, int i, char **params);
int eject(server *server, int i, char **params);
int _fork(server *server, int i, char **params);
int incantation(server *server, int i, char **params);
int inventory(server *server, int i, char **params);
int set(server *server, int i, char **params);
int look(server *server, int i, char **params);
int msz(server *server, int i, char **params);
int mct(server *server, int i, char **params);
int forward(server *server, int i, char **params);
int left(server *server, int i, char **params);
int right(server *server, int i, char **params);
int pin(server *server, int i, char **params);
int plv(server *server, int i, char **params);
int sgt(server *server, int i, char **params);
int take(server *server, int i, char **params);
int tna(server *server, int i, char **params);
int pdi(server *server);
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
void	manage_client(server *server, fd_set rdfs, char **buf);
void init_command(server *server);
void init_function_command(server *server);
char	**str_to_wordtab(char *str, char delimitor);
t_rsrc *init_inventory();
void manage_time(server *server);
s_execution *add_execution_list(s_execution *list, char *buffer);
s_execution *pop_element_execution(s_execution *list, int id_cmd);
void print_execution(s_execution *list);
double			get_time_micro();
int count_action(s_execution *list);

#endif /* SERVER_H_ */
