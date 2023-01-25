/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:57:25 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/01/25 21:48:32 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* calloc 2d array in size of map */
void	allocate_duplicate_memory(t_data *data)
{
	int	i;

	i = 0;
	data->duplicate = ft_calloc(data->rows + 1, sizeof(int *));
	if (!data->duplicate)
	{
		free_struct(data);
		error_msg_exit("Couldn't malloc data->duplicate to check the path\n");
	}
	while (i < data->rows)
	{
		data->duplicate[i] = ft_calloc(data->columns + 1, sizeof(int));
		i++;
	}
}

void	go_through_map(t_data *data, int row, int col)
{
	if (data->map[row][col] != '1' && !data->duplicate[row][col])
	{
		data->duplicate[row][col] = 1;
		go_through_map(data, row, col + 1);
		go_through_map(data, row, col - 1);
		go_through_map(data, row + 1, col);
		go_through_map(data, row - 1, col);
	}
}

void	check_access(t_data *data)
{
	int	collectible;
	int	map_exit;
	int	row;
	int	col;

	collectible = 0;
	map_exit = 0;
	row = -1;
	while (++row < data->rows)
	{
		col = -1;
		while (++col < data->columns)
		{
			if (data->map[row][col] == 'C' && data->duplicate[row][col])
				collectible++;
			if (data->map[row][col] == 'E' && data->duplicate[row][col])
				map_exit++;
		}
	}
	if (collectible + map_exit != data->collectible + 1)
	{
		error_msg_free_exit("Path is invalid!\n", data);
	}
}

void	check_path(t_data *data)
{
	allocate_duplicate_memory(data);
	go_through_map(data, data->row_pos, data->col_pos);
	check_access(data);
}

void	check_map(t_data *data)
{
	check_0_1_p_c_e(data);
	check_walls(data);
	check_p_c_e(data);
	check_path(data);
}
