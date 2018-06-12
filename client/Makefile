CC      = gcc -g

RM      = rm -f

CFLAGS += -Wextra -Wall -I include_client/

NAME_CLIENT    = ../zappy_ai

SRC_CLIENT     =        source_client/client.c \
			source_client/close_socket.c \
			source_client/connection_serveur.c \
			source_client/free_client.c \
			source_client/help_client.c \
			source_client/init_client.c \
			source_client/init_socket.c \
			source_client/isHostname.c \
			source_client/isPort.c \
			source_client/isWriteArguments.c \
			source_client/launch_client.c

OBJ_CLIENT     = $(SRC_CLIENT:.c=.o)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) -o $(NAME_CLIENT) $(CFLAGS) $(OBJ_CLIENT)
	@printf "\n[\33[1;32mOK\033[0;m] Binary : $(NAME_CLIENT)\n"

all: $(NAME_CLIENT)

clean:
	$(RM) $(OBJ_CLIENT)
	@printf "\n[\33[1;32mCLEAN\033[0;m] OBJ_CLIENT : $(OBJ_CLIENT)\n"
fclean:
	$(RM) $(OBJ_CLIENT)
	$(RM) $(NAME_CLIENT)
	@printf "\n[\33[1;32mCLEAN\033[0;m] Binary : myftp | OBJ_CLIENT : $(OBJ_CLIENT)\n\n"

re: fclean all

.PHONY: all clean fclean re server client

