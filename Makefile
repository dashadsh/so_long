# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:44:42 by dgoremyk          #+#    #+#              #
#    Updated: 2022/12/07 12:29:48 by dgoremyk         ###   ########.fr        #
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
