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

# define HEIGHT 20
# define WIDTH 20

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

int     server(char **av);

#endif /* SERVER_H_ */
