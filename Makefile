# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:44:42 by dgoremyk          #+#    #+#              #
#    Updated: 2022/12/06 19:35:47 by dgoremyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# run make inside mlx folder!

NAME = so_long
CC = gcc
#CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f
SRC = main.c
OBJ = $(SRC:.c=.o)
# APPLEFLAGS = -framework OpenGL -framework AppKit
MLXLIB = ./mlx/libmlx.a
LIBFT = ./libft/libft.a

# -I dir
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

# -C option is for running MAKE command on a subfolder
# add later one more make for libft
# -L ??? SEARCHES FOR LIBRARY ITSELF
# -l load
$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C mlx
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -o $(NAME)
#	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# $(CC) $(OBJ) $(CFLAGS) $(MLXLIB) -framework OpenGL -framework AppKit -o $(NAME)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
