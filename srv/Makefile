##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC      = gcc -g

RM      = rm -f

CFLAGS += -Wextra -Wall -I include/

NAME_SERVER    = ../zappy_server

SRC_SERVER     =        src/main.c \
			src/init_serv.c \
			src/init_list_team.c \
			src/init_zappy.c \
			src/fill_size_map.c \
			src/handle_client.c \
			src/command.c \
			src/commands/bct.c \
			src/commands/broadcast.c \
			src/commands/connect_nbr.c \
			src/commands/eject.c \
			src/commands/fork.c \
			src/commands/incantation.c \
			src/commands/elevation.c \
			src/commands/inventory.c \
			src/commands/look.c \
			src/commands/look2.c \
			src/commands/map_size.c \
			src/commands/set.c \
			src/commands/mct.c \
			src/commands/move.c \
			src/commands/pdi.c \
			src/commands/pin.c \
			src/commands/plv.c \
			src/commands/ppo.c \
			src/commands/sgt.c \
			src/commands/sst.c \
			src/commands/take.c \
			src/commands/tna.c \
			src/commands/handle_direction.c \
			src/init_map.c \
			src/set_rsrc.c \
			src/set_rsrcbis.c \
			src/utils.c \
			src/my_str_to_wordtab.c \
			src/inventory.c \
			src/execute_cmd.c \
			src/manage_time.c \
			src/init_execution.c \
			src/get_time_micro.c \
			src/win.c \

OBJ_SERVER     = $(SRC_SERVER:.c=.o)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) -o $(NAME_SERVER) $(CFLAGS) $(OBJ_SERVER)
	@printf "\n[\33[1;32mOK\033[0;m] Binary : $(NAME_SERVER)\n"

all: $(NAME_SERVER)

clean:
	$(RM) $(OBJ_SERVER)
	@printf "\n[\33[1;32mCLEAN\033[0;m] OBJ_SERVEUR : $(OBJ_SERVER)\n\n"
fclean:
	$(RM) $(OBJ_SERVER)
	$(RM) $(NAME_SERVER)
	@printf "\n[\33[1;32mCLEAN\033[0;m] Binary : server | OBJ_SERVEUR : $(OBJ_SERVER)\n\n"

re: fclean all

.PHONY: all clean fclean re server client
