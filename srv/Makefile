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
			src/init_client.c \
			src/ring_buffer.c \
			src/handle_client.c

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
