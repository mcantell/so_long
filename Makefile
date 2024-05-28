# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 13:43:10 by mcantell          #+#    #+#              #
#    Updated: 2024/05/27 19:48:06 by mcantell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = 	-Wall -Werror -Wextra -g

HEADER_DIR = ./include

SRC_DIR = ./src

MINILIBX_PATH = ./mlx
MINILIBX = libmlx.a

SRC = ft_strutils.c so_long.c get_next_line.c get_next_line_utils.c strjoin.c cop_map.c \
matrix_len.c check_path.c ft_free.c matrix_copy.c display.c\

INC = -I$(HEADER_DIR) -I$(MINILIBX_PATH)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(CFLAGS) $(INC) -c $< -o $@

OBJ = $(patsubst %.c, $(SRC_DIR)/%.o, $(SRC))

$(NAME): $(OBJ) $(MINILIBX)
	gcc $(OBJ) $(CFLAGS) -L$(MINILIBX_PATH) -lmlx_Linux -lXext -lX11 -lm  -o $(NAME)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_PATH)

all: $(NAME)

norma:
	norminette $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_PATH) clean

re: fclean all


$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)/configure
	make -C $(MINILIBX_PATH)

.PHONY: all, clean, fclean, re
