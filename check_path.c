
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
	// here we need +1 to END THE MAP
	if (!data->duplicate) 	// otherwithe it will be: sizeof(char)
	{
		free_struct(data);
		error_msg("Couldn't malloc data->duplicate to check the path\n");
		exit(EXIT_FAILURE);
	}
	while (i < data->rows)
	{
		data->duplicate[i] = ft_calloc(data->columns, sizeof(int)); // +1 ??
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
			error_msg("Couldn't access all collectibles/exit!\n");
			exit(EXIT_FAILURE);
		}
}

void	check_valid_path(t_data *data)
{
	allocate_duplicate_memory(data);
	go_through_map(data, data->row_pos, data->col_pos);
	// int y = -1;
	// int x;
	// while (++y < data->rows)
	// {
	// 	x = -1;
	// 	while  (++x < data->columns)
	// 	{
	// 		printf("%i ", data->duplicate[y][x]);
	// 	}
	// 	printf("\n");
	// }
	check_access(data);
}