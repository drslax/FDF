# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 21:52:24 by aelouarg          #+#    #+#              #
#    Updated: 2018/11/24 01:52:27 by aelouarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/line.c src/param.c src/render.c src/fdf.c src/main.c src/parse.c src/rotate.c

OBJ = src/line.o src/param.o src/render.o src/fdf.o src/main.o src/parse.o src/rotate.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@cc $(CFLAGS) -I /usr/local/include $(SRC) -L /usr/local/lib -lmlx -L libft/ -lft -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
