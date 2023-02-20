# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:44:42 by dgoremyk          #+#    #+#              #
#    Updated: 2023/02/20 16:24:21 by dgoremyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# run make inside mlx folder!

NAME = so_long
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f

SRC_PATH = src/
OBJ_PATH = obj/

SRC = main.c free_struct.c create_map.c early_error_check.c finish.c read_map.c rectangular_check.c check_map.c check_path.c error_msg.c launch_graphics.c moves.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
# APPLEFLAGS = -framework OpenGL -framework AppKit

# library stated like a custom one
# #include <mlx.h>
MLXLIB = ./mlx/libmlx.a
LIBFT = ./libft/libft.a

# -I dir

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
#%.o: %.c
#	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C mlx
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# $(CC) $(OBJ) $(CFLAGS) $(MLXLIB) -framework OpenGL -framework AppKit -o $(NAME)


clean:
	$(MAKE) clean -C mlx
	$(MAKE) clean -C libft
	$(RM) $(OBJS)
	
fclean: clean
	$(MAKE) clean -C mlx
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
