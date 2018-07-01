all:
	@(cd ./client/Client_developed_in_CPP/ && $(MAKE))
	@(cd ./srv/ && $(MAKE))
	@(cd ./Gui/ && $(MAKE))

server:
	@(cd ./srv/ && $(MAKE))

client:
	@(cd ./client/Client_developed_in_CPP/ && $(MAKE))

gui:
	@(cd ./Gui/ &&$(MAKE))

clean:
	cd ./srv/ && ($(MAKE) clean)
	cd ./client/Client_developed_in_CPP/ && ($(MAKE) clean)
	cd ./Gui/ && ($(MAKE) clean)
fclean:
	cd ./srv/ && ($(MAKE) fclean)
	cd ./client/Client_developed_in_CPP/ && ($(MAKE) fclean)
	cd ./Gui/ && ($(MAKE) fclean)

re: fclean all

.PHONY: all clean fclean re server client
