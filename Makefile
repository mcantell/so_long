# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcantell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 13:43:10 by mcantell          #+#    #+#              #
#    Updated: 2024/05/10 14:46:53 by mcantell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = 	-Wall -Werror -Wextra

MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

SRC = ft_strutils.c so_long.c get_next_line.c get_next_line_utils.c strjoin.c cop_map.c \
matrix_len.c \

%.o: %.c
	gcc $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(MINILIBX)
	gcc $(OBJ) $(CFLAGS) $(MINILIBX) mlx/libmlx.a -L./mlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)/configure
	make -C $(MINILIBX_PATH)

.PHONY: all, clean, fclean, re