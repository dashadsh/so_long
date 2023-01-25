

#include "so_long.h"

void	finish_the_game(t_data *data)
{
		data->steps++;
		display_steps(data);
		ft_putstr_fd("mouse just left on the balloon!\n", 1);
		exit_game(data);
}

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall_img);
	mlx_destroy_image(data->mlx_ptr, data->floor_img);
	mlx_destroy_image(data->mlx_ptr, data->player_img);
	mlx_destroy_image(data->mlx_ptr, data->collectible_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_img);
	mlx_destroy_image(data->mlx_ptr, data->winner_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_struct(data);
	exit(0);
}

int	key_hook(int key, t_data *data)
{
	if (key == KEY_ESC)
		exit_game(data);
	else if (key == KEY_D)
		move_d(data);
	else if (key == KEY_W)
		move_w(data);
	else if (key == KEY_A)
		move_a(data);
	else if (key == KEY_S)
		move_s(data);
	return(0);
}

void	launch_graphics(t_data *data)
{
	data->mlx_ptr = mlx_init(); // initialize MiniLibX 

	data->win_ptr = mlx_new_window(data->mlx_ptr, SIZE * data->columns, SIZE * data->rows, "mouse getting into fights");
	data->last_pos = '0'; // should be initialized
	set_img_ptr(data);	
	create_map(data);
	display_steps(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, X_CLOSE, 0, exit_game, data); //closes game with mouse
	mlx_loop(data->mlx_ptr);
}