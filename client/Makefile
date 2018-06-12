##
## EPITECH PROJECT, 2018
## PSU_zappy_2017
## File description:
## Makefile
##

CC      = gcc -g

RM      = rm -f

CFLAGS += -Wextra -Wall -I include_client/

NAME_CLIENT    = ../zappy_ai

SRC_CLIENT     =        source_client/handle_client/client.c 			\
			source_client/handle_socket/close_socket.c 		\
			source_client/handle_socket/connection_server.c 	\
			source_client/handle_client/free_client.c 		\
			source_client/handle_client/help_client.c 		\
			source_client/handle_client/init_client.c 		\
			source_client/handle_socket/init_socket.c 		\
			source_client/handle_arguments/isHostname.c 		\
			source_client/handle_arguments/isPort.c 		\
			source_client/handle_arguments/isWriteArguments.c 	\
			source_client/handle_client/launch_client.c		\
			source_client/handle_instructions/execute_instruction.c	\
			source_client/handle_instructions/find_instruction.c	\
			source_client/handle_instructions/init_instructions.c	\
			source_client/handle_instructions/instructions.c	\
			source_client/handle_instructions/read_instruction.c	\
			source_client/handle_instructions/send_instruction.c	\
			source_client/handle_instructions/get_instruction.c	\
			source_client/handle_instructions/instructions_2.c	\
			source_client/handle_instructions/print_instruction.c	\
			source_client/library/get_next_line.c


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

