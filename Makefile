all:
	@(cd ./client/Client_developed_in_CPP/ && $(MAKE))
	@(cd ./srv/ && $(MAKE))

server:
	@(cd ./srv/ && $(MAKE))

client:
	@(cd ./client/Client_developed_in_CPP/ && $(MAKE))

clean:
	cd ./srv/ && ($(MAKE) clean)
	cd ./client/Client_developed_in_CPP/ && ($(MAKE) clean)
fclean:
	cd ./srv/ && ($(MAKE) fclean)
	cd ./client/Client_developed_in_CPP/ && ($(MAKE) fclean)

re: fclean all

.PHONY: all clean fclean re server client
