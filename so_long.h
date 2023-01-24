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

# define SIZE 128 // which size set?? size of img
# define WALL "./img/wall.xpm"
# define FLOOR "./img/floor.xpm"
# define PLAYER "./img/player.xpm"
# define COLLECTIBLE "./img/collectible.xpm"
# define EXIT "./img/exit.xpm"
// # define UP 13
// # define DOWN 1
// # define RIGHT 2
// # define LEFT 0
// # define ESC 53

typedef struct s_data
{
	char	**map;
	int		rows;
	int		columns;
	int		player;
	int		collectible;
	// int 	score; // NEEDED? 0 by default
	int		exit;
	int		row_pos; // P position
	int		col_pos; // P position
	int		**duplicate;


	void	*mlx_ptr;
	void	*win_ptr;
	// void	*img_ptr;

	// mlx_xpm_to_image returns a non-null pointer as an image identifier
	// sets the img_wh (width/hight) accordingly
	void	*floor_img;
	void	*wall_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	int		img_wh;
} 				t_data;

/* error.c */
void 	error_msg(char *msg);

/* read_map.c */
int		open_file(t_data *data, char **av);
// void	count_row_length(t_data *data, char **av); // to be deleted?
void	count_rows(t_data *data, char **av);
void 	allocate_map_memory(t_data *data);
void	read_map(t_data *data, char **av);

/* check_map.c */
void	check_0_1_p_c_e(t_data *data);
void 	check_walls(t_data *data);
void	count_p_c_e(t_data *data);
void	check_p_c_e(t_data *data);
void	check_map(t_data *data);

/* check_path.c */
void	allocate_duplicate_memory(t_data *data);
void	go_through_map(t_data *data, int y, int x);
void	check_access(t_data *data);
void	check_valid_path(t_data *data);

/* main.c */
void	ft_clear(char **str);
void	free_struct(t_data *data);
void	dot_ber_check(char **av);
void 	early_error_check(int ac, char **av);
int 	main(int ac, char **av);

/* graphics.c */
//void	run_window(void);
void	load_img(t_data *data);
void	launch_graphics(t_data *data);

# endif
