all:
	@(cd ./client/ && $(MAKE))
	@(cd ./srv/ && $(MAKE))

server:
	@(cd ./srv/ && $(MAKE))

client:
	@(cd ./client/ && $(MAKE))

clean:
	cd ./srv/ && ($(MAKE) clean)
	cd ./client/ && ($(MAKE) clean)
fclean:
	cd ./srv/ && ($(MAKE) fclean)
	cd ./client/ && ($(MAKE) fclean)

re: fclean all

.PHONY: all clean fclean re server client
