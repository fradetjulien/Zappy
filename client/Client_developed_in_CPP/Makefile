##
## EPITECH PROJECT, 2018
## PSU_zappy_2017
## File description:
## Makefile
##

CC      = g++ -g

RM      = rm -f

CPPFLAGS += -Wextra -Wall -I ../../include_client

NAME_CLIENT    = ../../zappy_ai

SRC_CLIENT     =source_client/handle_client/client.cpp 			\
		source_client/handle_client/launchClient.cpp		\
		source_client/handle_arguments/isWriteArguments.cpp 	\
		source_client/handle_arguments/isHostname.cpp 		\
		source_client/handle_arguments/isWelcome.cpp 		\
		source_client/handle_arguments/isPort.cpp	 	\
		source_client/handle_arguments/helpClient.cpp 		\
		source_client/handle_fdset/checkFDS.cpp		 	\
		source_client/handle_fdset/initFDS.cpp		 	\
		source_client/handle_instruction/getInstruction.cpp	\
		source_client/handle_instruction/printInstruction.cpp	\
		source_client/handle_instruction/sendInstruction.cpp	\
		source_client/handle_server/contactServer.cpp		\
		source_client/handle_server/remainingPlaces.cpp		\
		source_client/handle_server/worldDimension.cpp		\
		source_client/handle_socket/initSocket.cpp 		\
		source_client/handle_socket/closeSocket.cpp 		\
		source_client/handle_socket/connectionServer.cpp	\
		source_client/exception.cpp \
		source_client/main.cpp

OBJ_CLIENT     = $(SRC_CLIENT:.cpp=.o)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) -o $(NAME_CLIENT) $(CPPFLAGS) $(OBJ_CLIENT)
	@printf "\n[\33[1;32mOK\033[0;m] Binary : $(NAME_CLIENT)\n"

all: $(NAME_CLIENT)

clean:
	$(RM) $(OBJ_CLIENT)
	@printf "\n[\33[1;32mCLEAN\033[0;m] OBJ_CLIENT : $(OBJ_CLIENT)\n"
fclean:
	$(RM) $(OBJ_CLIENT)
	$(RM) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re server client
