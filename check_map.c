

#include "so_long.h"

//=============MINE============================== 
// map exists - DONE WHEN READ
// map >= 3 rows ???
// map >= 3 columns ???
//============ASSIGNMENT============================
// map has walls, collectible, free space - GAME CAN START W/O FREE SPACE (COVERED WITH COLLECTIBLE)
// map contains only 01CEP - DONE
// map contains 1 exit, 1 player - DONE
// map has >=1 collectible - DONE
// map is rectangular  - DONE WHEN READ
// map is surrounded by walls - DONE
// map should contain valid path (C and E should be reachable for P)
//===============================================
// what if there are /n chars after the map???
void	check_0_1_p_c_e(t_data *data)
{
	int	row;
	int	col;

	row = -1;
	while(data->map[++row])
	{
		col = -1;
		while(data->map[row][++col])
		{
			if (!ft_strchr("01PCE", data->map[row][col]))
			{
				// printf("row: %d	column: %d\n", row, column);
				free_struct(data);
				error_msg("Map should contain 01PCE chars only\n");
				exit(EXIT_FAILURE);
			}
		}
	//	printf("inner loop end. column outside the range\nrow: %d	column: %d\n", row, column);
	}
//	printf("outer loop end. row/column outside the range\nrow: %d	column: %d\n", row, column);
}

void	check_walls(t_data *data)
{
	int	row;
	int	col;

	row = -1;
	col = -1;
	// printf("col length/amt of rows: %d\n", data->rows);
	// printf("highest row index: %d\n", data->rows-1);
	// printf("row length/amt of columns: %d\n", data->columns);
	// printf("highest column index: %d\n", data->columns-1);
	while(data->map[0][++col])
	{
		if ((data->map[0][col] != '1')
			|| (data->map[data->rows-1][col] != '1'))
			{
				free_struct(data);
				error_msg("Surrounding wall should contain '1' only\n");
				exit(EXIT_FAILURE);
			}
	}
	// printf("loop for horizontal walls ended\ncolumn outside of range: %d\n\n", column);
	while(data->map[++row])
		if ((data->map[row][0] != '1')
			|| (data->map[row][data->columns-1] != '1'))
			{
				free_struct(data);
				error_msg("Surrounding wall should contain '1' only\n");
				exit(EXIT_FAILURE);
			}
	// printf("loop for vertical walls ended\nrow outside of range: %d\n\n", row);
}

void	count_p_c_e(t_data *data)
{
	int	row;
	int	col;

	row = -1;
	while(data->map[++row])
	{
		col = -1;
		while(data->map[row][++col])
		{
			if (data->map[row][col] == 'P')
			{
				data->player++;
				// printf("P: %i\n", data->player); //printed an address at some point! WHY??
				data->row_pos = row; //seems confusing... but it's correct order
				data->col_pos = col;
			}
			else if (data->map[row][col] == 'C')
			{
				data->collectible++;
				// printf("C: %i\n", data->collectible);
			}
			else if (data->map[row][col] == 'E')
			{
				data->exit++;
				// printf("E: %i\n", data->exit);
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
		error_msg("Map should contain 1 player and 1 exit\n");
		exit(EXIT_FAILURE);
	}
	if (data->collectible < 1)
	{
		free_struct(data);
		error_msg("Map should contain at least one collectible\n");
		exit(EXIT_FAILURE);
	}
}

void	check_map(t_data *data)
{
	check_0_1_p_c_e(data);
	check_walls(data);
	check_p_c_e(data);
}	