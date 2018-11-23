# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 21:52:24 by aelouarg          #+#    #+#              #
#    Updated: 2018/11/23 07:13:24 by aelouarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = *.c

OBJ = *.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@cc -I /usr/local/include $(SRC) -L /usr/local/lib -lmlx -L libft/ -lft -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I libft

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
