/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:33:07 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:50:14 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Three identifiers are needed here for the connection to the display, 
the window to use, and the image 
(respectively mlx_ptr , win_ptr and img_ptr ). 

The (x , y) coordinates define where the image should be placed in the window.

that function displays immideately matching image depending on a 
corresponding char in a map
*/
void	put_img(t_data *data, int row, int col)
{
	if (data->map[row][col] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall_img, SIZE * col, SIZE * row);
	else if (data->map[row][col] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor_img, SIZE * col, SIZE * row);
	else if (data->map[row][col] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collectible_img, SIZE * col, SIZE * row);
	else if (data->map[row][col] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_img, SIZE * col, SIZE * row);
	else if (data->map[row][col] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit_img, SIZE * col, SIZE * row);
}

/*
create map  - goes through entire map
uses function void	put_img(t_data *data, int row, int col) which refers to
mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall_img, SIZE * col, SIZE * row);
that function displays immideately matching image depending on a 
corresponding char in a map
*/
void	create_map(t_data *data)
{
	int	row;
	int	col;

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
displaying steps of our moves during the game
*/
void	display_steps(t_data *data)
{
	char	*steps;

	steps = ft_itoa(data->steps);
	ft_putstr_fd("steps: ", 1);
	ft_putstr_fd(steps, 1);
	ft_putstr_fd("\n", 1);
	free(steps);
}

/*
int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param)
mlx_key_hook(data->win_ptr, key_hook, data);
uses my own function: int	key_hook(int key, t_data *data)
we match some keys with commands should be executing when pressing those keys.
*/
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
	return (0);
}
