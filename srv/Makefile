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
			src/ring_buffer.c \
			src/handle_client.c \
			src/command.c \
			src/commands/bct.c \
			src/commands/broadcast.c \
			src/commands/connect_nbr.c \
			src/commands/eject.c \
			src/commands/fork.c \
			src/commands/incantation.c \
			src/commands/inventory.c \
			src/commands/look.c \
			src/commands/map_size.c \
			src/commands/mct.c \
			src/commands/move.c \
			src/commands/pin.c \
			src/commands/plv.c \
			src/commands/ppo.c \
			src/commands/sgt.c \
			src/commands/sst.c \
			src/commands/take.c \
			src/commands/tna.c

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
