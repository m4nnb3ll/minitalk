NAME = server client

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRV_SRCS = server.c
CLT_SRCS = client.c

all: $(NAME)

server: $(SRV_SRCS)
		$(CC) $(CFLAGS) $(SRV_SRCS) libft/libft.a -o server

client: $(CLT_SRCS)
		$(CC) $(CFLAGS) $(CLT_SRCS) libft/libft.a -o client

clean:
	rm -f $(SRV_OBJS) $(CLT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
