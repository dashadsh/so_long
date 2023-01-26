# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:44:42 by dgoremyk          #+#    #+#              #
#    Updated: 2023/01/26 11:59:28 by dgoremyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# run make inside mlx folder!

NAME = so_long
CC = gcc
#CFLAGS = -g
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f
SRC = main.c utils.c free_struct.c create_img.c early_error_check.c read_map.c read_map2.c messages.c check_map1.c check_map2.c error_msg.c graphics.c moves.c
OBJ = $(SRC:.c=.o)
# APPLEFLAGS = -framework OpenGL -framework AppKit

# library stated like a custom one
# #include <mlx.h>
MLXLIB = ./mlx/libmlx.a
LIBFT = ./libft/libft.a

# -I dir
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C mlx
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# $(CC) $(OBJ) $(CFLAGS) $(MLXLIB) -framework OpenGL -framework AppKit -o $(NAME)

#	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C mlx
	$(MAKE) clean -C libft
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) clean -C mlx
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
