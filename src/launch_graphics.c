/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:08:18 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:47:47 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
&img_wh - size of image, after loading will be saved in this variable
we could have saved that into struct,
but since we are not using it i've just created variable in a function
*/
void	set_img_ptr(t_data *data)
{
	int	img_wh;

	img_wh = 0;
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr,
			FLOOR, &img_wh, &img_wh);
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr,
			WALL, &img_wh, &img_wh);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER, &img_wh, &img_wh);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr,
			COLLECTIBLE, &img_wh, &img_wh);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr,
			EXIT, &img_wh, &img_wh);
}

/*
1. mlx_init()  - init MLX library
establish a connection to the correct graphical system,
will return (void *) which holds the location of our current MLX instance.

2. mlx_new_window() returns (*) to the window we have just created. 
We can give the window height, width and a title. 
init a window which'll stay open (ctrl + c to close)

3. set_img_ptr(data); needed to add images to our struct
&img_wh - size of image, after loading will be saved in this variable
we could have saved that into struct,
but since we are not using it i've just created variable in a function

4. create map  - goes through entire map
uses function void	put_img(t_data *data, int row, int col) which refers to
mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall_img, SIZE * col, SIZE * row);
that function displays immideately matching image depending on a 
corresponding char in a map

5. displaying steps of our moves during the game

6. int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param)
mlx_key_hook(data->win_ptr, key_hook, data);
uses my own function: int	key_hook(int key, t_data *data)
we match some keys with commands should be executing when pressing those keys.

7. int	mlx_hook(void *win_ptr, int x_event, int x_mask, 
			int (*funct)(), void *param);
x_mask argument of mlx_hook is useless on macos, keep it at 0:
mlx_hook(data->win_ptr, X_CLOSE, 0, exit_game, data); 
makes possible to close game with mouse

8. mlx_loop(): A single parameter is needed, the connection identifier mlx_ptr.
Both X-Window and MacOSX graphical systems are bi-directionnal. 
On one hand, the program sends orders to the screen to display pixels, images...
On the other hand, it can get information from the keyboard and mouse 
associated to the screen. 
To do so, the program receives "events" from the keyboard or the mouse. 
To receive events, you must use this function. This function never returns. 
It is an infinite loop that waits for an event, 
and then calls a user-defined function associated with this event. 
*/
void	launch_graphics(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, SIZE * data->columns,
			SIZE * data->rows, "mouse getting into fights");
	data->last_pos = '0';
	set_img_ptr(data);
	create_map(data);
	display_steps(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, X_CLOSE, 0, exit_game, data);
	mlx_loop(data->mlx_ptr);
}
