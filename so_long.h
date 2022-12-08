#ifndef SO_LONG_H
# define SO_LONG_H 

#include "./mlx/mlx.h"
#include "./libft/libft.h"

/* library for printf*/
# include <stdio.h> 
/* library for open*/
# include <fcntl.h>
/* library for read, write, close, (lseek) */
# include <unistd.h>
/* library for malloc, EXIT_SUCCESS; EXIT_FAILURE*/
# include <stdlib.h>

# include <stdbool.h>

typedef struct s_data
{
	char	**map;
	int		rows;
	int		columns;
	int		player;
	int		collectible;
	int		exit;
	int		player_row_pos;
	int		player_col_pos;
} 				t_data;

/* error.c */
void 	error_msg(char *msg);

/* read_map.c */
int		open_file(t_data *data, char **av);
// void	count_row_length(t_data *data, char **av); // to be deleted?
void	count_rows(t_data *data, char **av);
void 	allocate_map_memory(t_data *data);
void	read_map(t_data *data, char **av);

/* check_path.c */

/* check_map.c */
void	check_0_1_p_c_e(t_data *data);
void 	check_walls(t_data *data);
void	count_p_c_e(t_data *data);
void	check_p_c_e(t_data *data);
void	check_map(t_data *data);

/* main.c */
void	ft_clear(char **str);
void	free_struct(t_data *data);
void	dot_ber_check(char **av);
void 	early_error_check(int ac, char **av);
int 	main(int ac, char **av);
# endif
