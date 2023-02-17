/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:19:26 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:13:30 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* 
1. void	allocate_duplicate_memory(t_data *data)
calloc 2d array in size of the original map
we fill it with ZEROES

i'm not sure if i need to calloc +1 for struct

2. void	go_through_map(t_data *data, int row, int col)
function go_through_map recursively goes through map
comparing to original map
we cannot step on walls (1) so we dont visit them

we mark all fields we could access with 1 char
it's called depth first search algorythm  

3. void	check_access(t_data *data)
we check if spot when we have P C E on original map
is equal to 1 on a duplicate map
*/
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
