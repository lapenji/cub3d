# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboncine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 12:45:42 by aboncine          #+#    #+#              #
#    Updated: 2023/02/22 17:01:39 by aboncine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRCS = main.c check_map.c check_map_functions.c get_next_line_utils.c \
	get_next_line.c hooks.c init.c mlx_utils.c raycasting.c rendering.c \
	utils.c utils2.c create_colors.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MINILIBX = -lXext -lX11 -lm -lz
LIB = -L minilibx-linux -lmlx

%.o: %.c
	$(CC) -c $(CFLAGS) $?

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB) $(MINILIBX) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
