NAME = libft.a

SRC = *.c

OBJS = *.o

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -c $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
