
#include "so_long.h"

//==================CHECK=VALID=PATH======================
// create duplicate map
 
//what about + 1 for allocation???

/* calloc 2d array in size of map */
void	allocate_duplicate_memory(t_data *data)
{
	int i;

	i = 0;
	data->duplicate = ft_calloc(data->rows + 1, sizeof(int *)); // array of pointers
	// no need 
	if (!data->duplicate) 	// otherwithe it will be: sizeof(char)
	{
		free_struct(data);
		error_msg_exit("Couldn't malloc data->duplicate to check the path\n");
	}
	while (i < data->rows)
	{
		data->duplicate[i] = ft_calloc(data->columns + 1, sizeof(int)); // +1 ??
		i++;
	}
}

void	go_through_map(t_data *data, int row, int col) //y starts with 0, columns with 1
{
	if (data->map[row][col] != '1' && !data->duplicate[row][col])  // != 1
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
		while  (++col < data->columns)
		{
			if (data->map[row][col] == 'C' && data->duplicate[row][col]) //make sure this spot was visited
				collectible++;
			if (data->map[row][col] == 'E' && data->duplicate[row][col])
				map_exit++;
		}
	}
	// printf("%i\n", c);
	// printf("%i\n", data->collectible);
	// printf("%i\n", e);
	if (collectible + map_exit != data->collectible + 1)
		{
			free_struct(data);
			error_msg_exit("Couldn't access all collectibles/exit!\n");
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