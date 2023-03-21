/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:19:35 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:13:26 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* 
functions checks if the map contains 01PCE chars - 
if current char is not present in array 01PCE - throws the error 
*/
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

/*
walls should vontain char 1 only
*/
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

/*
one player
one exit
at least one coolectible

this function counts all of them for future use in function check_p_c_e
*/
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

/*
one player
one exit
at least one coolectible on a map
*/
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

void	check_map(t_data *data)
{
	check_0_1_p_c_e(data);
	check_walls(data);
	check_p_c_e(data);
	check_path(data);
}
