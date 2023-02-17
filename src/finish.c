/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:01:57 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:52:14 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_c(t_data *data)
{
	int	collectible;
	int	row;
	int	col;

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

void	finish_the_game(t_data *data)
{
	data->steps++;
	display_steps(data);
	ft_putstr_fd("mouse just escaped on the balloon!\n", 1);
	exit_game(data);
}

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall_img);
	mlx_destroy_image(data->mlx_ptr, data->floor_img);
	mlx_destroy_image(data->mlx_ptr, data->player_img);
	mlx_destroy_image(data->mlx_ptr, data->collectible_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_struct(data);
	exit(0);
}
