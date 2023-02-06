NAME = client server

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): client.c server.c
	@make -C libft/ bonus
	$(CC) $(CFLAGS) client.c -L./libft/ -lft -o client
	$(CC) $(CFLAGS) server.c -L./libft/ -lft -o server

bonus: client_bonus.c server_bonus.c
	@make -C libft/ bonus	
	$(CC) $(CFLAGS) client_bonus.c -L./libft/ -lft -o client
	$(CC) $(CFLAGS) server_bonus.c -L./libft/ -lft -o server
	@touch bonus

clean:
	rm -f client.o server.o client_bonus.o server_bonus.o

fclean: clean
	rm -f $(NAME)
	@rm -f bonus

re: fclean all

.PHONY: all clean fclean re
