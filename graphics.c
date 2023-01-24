

#include "so_long.h"

// mlx_init()  - establish a connection to the correct graphical system,
// 	will return (void *) which holds the location of our current MLX instance. 

// mlx_new_window() returns (*) to the window we have just created. 
// We can give the window height, width and a title. 

// mlx_loop() initiates the window rendering.
// Wait for keyboard and mouse input in the popped window. 
//--------------------------------------------------------------------------


// void	run_window(void)
// {
// 	void *mlx_ptr;
// 	void *win_ptr; //or delete

// 	mlx_ptr = mlx_init(); // initialize MiniLibX 

// 	// mlx_new_window(mlx, 500, 300, "OVERGAME");
// 	win_ptr = mlx_new_window(mlx_ptr, 1000, 500, "GAME OVER"); //w w w error - variable 'win' set but not used
// 	mlx_loop(mlx_ptr);
// }

//--------------------------------------------------------------------------

/* Converts an xpm file to a new image instance.
loads the images and defined pointer points to given image

It will also SET (!!! => &data->img_wh) the img_wh (width/hight) accordingly, 
which is ideal when reading sprites

does it needed to be saved in t_data data??
*/
// void	load_img(t_data *data)
// {
// 	// data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &data->img_wh, &data->img_wh);
// 	// data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &data->img_wh, &data->img_wh);
// 	// data->player_img = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &data->img_wh, &data->img_wh);
// 	// data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLE, &data->img_wh, &data->img_wh);
// 	// data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &data->img_wh, &data->img_wh);

// 	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, 0, 0);
// 	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, WALL, 0, 0);
// 	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, 0, 0);
// 	data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLE, 0, 0);
// 	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, 0, 0);

// 	// data->floor_img = mlx_xpm_file_to_image(data->floor_img, FLOOR, &data->img_wh, &data->img_wh);
// 	// data->wall_img = mlx_xpm_file_to_image(data->wall_img, WALL, &data->img_wh, &data->img_wh);
// 	// data->player_img = mlx_xpm_file_to_image(data->player_img, PLAYER, &data->img_wh, &data->img_wh);
// 	// data->collectible_img = mlx_xpm_file_to_image(data->collectible_img, COLLECTIBLE, &data->img_wh, &data->img_wh);
// 	// data->exit_img = mlx_xpm_file_to_image(data->exit_img, EXIT, &data->img_wh, &data->img_wh);
// }

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

// void	put_img_to_map(t_data *data)
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
/*

mlx_loop():
 Both X-Window and MacOSX graphical systems are bi-directionnal. 
 On one hand, the program sends orders to the screen to display pixels, images, and so on. 
 On the other hand, it can get information from the keyboard and mouse associated to the screen. 
 To do so, the program receives "events" from the keyboard or the mouse. 
 To receive events, you must use this function. This function never returns. 
 It is an infinite loop that waits for an event, and then calls a user-defined function associated with this event. 
 A single parameter is needed, the connection identifier mlx_ptr.
*/
void	launch_graphics(t_data *data)
{
	// load_img(data);
	data->mlx_ptr = mlx_init(); // initialize MiniLibX 

	data->win_ptr = mlx_new_window(data->mlx_ptr, SIZE * data->columns, SIZE * data->rows, "GAME OVER");

	// // put_img_to_map(data);
	mlx_loop(data->mlx_ptr);

}