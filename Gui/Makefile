CC      = g++ -g

RM      = rm -f

CPPFLAGS += -Wextra -Wall -I include -lsfml-graphics -lsfml-window -lsfml-system

NAME_CLIENT    = ../zappy_gui

SRC_CLIENT     =source/algoGui.cpp \
		source/connectServer.cpp \
		source/exception.cpp \
		source/gui.cpp \
		source/case.cpp \
		source/guiClient.cpp \
		source/main.cpp

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

.PHONY: all clean fclean re server client gui
