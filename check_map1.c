/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:56:22 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/16 15:29:23 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_0_1_p_c_e(t_data *data)
{
	int	row;
	int	col;

	row = -1;
	while (data->map[++row])
	{
		col = -1;
		while (data->map[row][++col])
		{
			if (!ft_strchr("01PCE", data->map[row][col]))
			{
				free_struct(data);
				error_msg_exit("Map should contain 01PCE chars only\n");
			}
		}
	}
}

void	check_walls(t_data *data)
{
	int	row;
	int	col;

	row = -1;
	col = -1;
	while (data->map[0][++col])
	{
		if ((data->map[0][col] != '1')
			|| (data->map[data->rows - 1][col] != '1'))
		{
			free_struct(data);
			error_msg_exit("Surrounding wall should contain '1' only\n");
		}
	}
	while (data->map[++row])
	{
		if ((data->map[row][0] != '1')
			|| (data->map[row][data->columns - 1] != '1'))
		{
			free_struct(data);
			error_msg_exit("Surrounding wall should contain '1' only\n");
		}
	}
}

void	count_p_c_e(t_data *data)
{
	int	row;
	int	col;

	row = -1;
	while (data->map[++row])
	{
		col = -1;
		while (data->map[row][++col])
		{
			if (data->map[row][col] == 'P')
			{
				data->player++;
				data->row_pos = row;
				data->col_pos = col;
			}
			else if (data->map[row][col] == 'C')
			{
				data->collectible++;
			}
			else if (data->map[row][col] == 'E')
			{
				data->exit++;
			}
		}
	}
}

void	check_p_c_e(t_data *data)
{
	count_p_c_e(data);
	if (data->player != 1 || data->exit != 1)
	{
		free_struct(data);
		error_msg_exit("Map should contain 1 player and 1 exit\n");
	}
	if (data->collectible < 1)
	{
		free_struct(data);
		error_msg_exit("Map should contain at least one collectible\n");
	}
}


/*
=============MINE============================== 
map exists - DONE WHEN READ
map >= 3 rows ???
map >= 3 columns ???
============ASSIGNMENT============================
map has walls, collectible, free space - 
GAME CAN START W/O FREE SPACE (COVERED WITH COLLECTIBLE)
map contains only 01CEP - DONE
map contains 1 exit, 1 player - DONE
map has >=1 collectible - DONE
map is rectangular  - DONE WHEN READ
map is surrounded by walls - DONE
map should contain valid path (C and E should be reachable for P)
===============================================
what if there are /n chars after the map???
*/

