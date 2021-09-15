CC = gcc
FLAGS = -Wall -Werror -Wextra
SERVER_APP = server
CLIENT_APP = client
LIBFT = libft.a


all : $(LIBFT) $(SERVER_APP) $(CLIENT_APP)

$(LIBFT) :
	make -C libft

$(SERVER_APP) : 
	$(CC) $(FLAGS) server.c libft/libft.a -o $@

$(CLIENT_APP) :
	$(CC) $(FLAGS) client.c libft/libft.a -o $@

%.o : %.c
	$(CC) $(FLAGS) $< -c

clean :
	make clean -C libft 
	rm -rf client.o server.o

fclean : clean
	make fclean -C libft
	rm -rf $(SERVER_APP) $(CLIENT_APP)

re : fclean all

re_client : 
	$(CC) $(FLAGS) client.c libft/libft.a -o client

re_server :
	$(CC) $(FLAGS) server.c libft/libft.a -o server

re_client_server :
	$(CC) $(FLAGS) client.c libft/libft.a -o client
	$(CC) $(FLAGS) server.c libft/libft.a -o server

