

#include "so_long.h"

// mlx_init()  - establish a connection to the correct graphical system,
// 	will return (void *) which holds the location of our current MLX instance. 

// mlx_new_window() returns (*) to the window we have just created. 
// We can give the window height, width and a title. 

// mlx_loop() initiates the window rendering.
// Wait for keyboard and mouse input in the popped window. 
//--------------------------------------------------------------------------

/* Converts an xpm file to a new image instance.
loads the images and defined pointer points to given image

It will also SET (!!! => &data->img_wh) the img_wh (width/hight) accordingly, 
which is ideal when reading sprites
*/
void	set_img_ptr(t_data *data)
{
	// working - img_wh from data should be removed
	int img_wh;

	img_wh = 0;
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &img_wh, &img_wh);
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &img_wh, &img_wh);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &img_wh, &img_wh);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLE, &img_wh, &img_wh);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &img_wh, &img_wh);
	data->exit_open_img = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_OPEN, &img_wh, &img_wh);
	data->winner_img = mlx_xpm_file_to_image(data->mlx_ptr, WINNER, &img_wh, &img_wh);

		// ---------------------------------------------------------------------------------------------
		// ALSO WORKING
	// data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &data->img_wh, &data->img_wh);
	// data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &data->img_wh, &data->img_wh);
	// data->player_img = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &data->img_wh, &data->img_wh);
	// data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLE, &data->img_wh, &data->img_wh);
	// data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &data->img_wh, &data->img_wh);
}

/*
Three identifiers are needed here for the connection to the display, 
the window to use, and the image 
(respectively mlx_ptr , win_ptr and img_ptr ). 

The (x , y) coordinates define where the image should be placed in the window.
*/

// void	put_img(t_data *data, void *img, int row, int col)
// {
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, SIZE * col, \
// 			SIZE * row);
// }

// void	create_map(t_data *data)
// {
// 	int	row;
// 	int	col;

// 	row = -1;
// 	while (++row < data->rows)
// 	{
// 		col = -1;
// 		while (++col < data->columns)
// 		{
// 			if (data->map[row][col] == '1')
// 				put_img(data, data->wall_img, row, col);
// 			else if (data->map[row][col] == '0')
// 				put_img(data, data->floor_img, row, col);
// 			else if (data->map[row][col] == 'C')
// 				put_img(data, data->collectible_img, row, col);
// 			else if (data->map[row][col] == 'P')
// 				put_img(data, data->player_img, row, col);
// 			else if (data->map[row][col] == 'E')
// 				put_img(data, data->exit_img, row, col);
// 		}
// 	}
// }
//--------------------------------------------------------------

// void	create_map(t_data *data)
// {
// 	int	row;
// 	int	col;
// 	row = -1;
// 	while (++row < data->rows)
// 	{
// 		col = -1;
// 		while (++col < data->columns)
// 		{
// 			if (data->map[row][col] == '1')
// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall_img, SIZE * col, SIZE * row);
// 			else if (data->map[row][col] == '0')
// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, SIZE * col, SIZE * row);
// 			else if (data->map[row][col] == 'C')
// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible_img, SIZE * col, SIZE * row);
// 			else if (data->map[row][col] == 'P')
// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img, SIZE * col, SIZE * row);
// 			else if (data->map[row][col] == 'E')
// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_img, SIZE * col, SIZE * row);
// 		}
// 	}
// }
//--------------------------------------------------------------


void	put_img(t_data *data, int row, int col)
{
	if (data->map[row][col] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall_img, SIZE * col, SIZE * row);
	else if (data->map[row][col] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, SIZE * col, SIZE * row);
	else if (data->map[row][col] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible_img, SIZE * col, SIZE * row);
	else if (data->map[row][col] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img, SIZE * col, SIZE * row);
	else if (data->map[row][col] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_img, SIZE * col, SIZE * row);
	else if (data->map[row][col] == 'O')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_open_img, SIZE * col, SIZE * row);
	else if (data->map[row][col] == 'W')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->winner_img, SIZE * col, SIZE * row);
}

void	create_map(t_data *data)
{
	int	row;
	int col;

	row = -1;
	while (++row < data->rows)
	{
		col = -1;
		while (++col < data->columns)
		{
			put_img(data, row, col);
		}
	}
}
/*
mlx_init() - init MLX library

mlx_new_window - init a window which'll stay open (ctrl + c to close)

int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param )

int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
mlx_hook = alters behaviour; 2 = KeyPress, x_mask argument of mlx_hook is useless on macos, keep it at 0
17 = DestroyNotify 1L<<2 = ButtonPressMask.

mlx_loop():
 Both X-Window and MacOSX graphical systems are bi-directionnal. 
 On one hand, the program sends orders to the screen to display pixels, images, and so on. 
 On the other hand, it can get information from the keyboard and mouse associated to the screen. 
 To do so, the program receives "events" from the keyboard or the mouse. 
 To receive events, you must use this function. This function never returns. 
 It is an infinite loop that waits for an event, and then calls a user-defined function associated with this event. 
 A single parameter is needed, the connection identifier mlx_ptr.

*/

void	create_new_map(t_data *data)
{
	create_map(data);
	display_steps(data);
}

int	is_c(t_data *data)
{
	int collectible;
	int row;
	int col;
	
	collectible = 0;
	row = -1;
	while (++row < data->rows)
	{
		col = -1;
		while (++col < data->columns)
		{
			if (data->map[row][col] == 'C')
				collectible++;
		}
	}
	return (collectible);
}