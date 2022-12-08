

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

void	check_0_1_p_c_e(t_data *data)
{
	int	row;
	int	column;

	row = -1;
	while(data->map[++row])
	{
		column = -1;
		while(data->map[row][++column])
		{
			if (!ft_strchr("01PCE", data->map[row][column]))
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
	int	column;
	int	row;

	column = -1;
	row = -1;
	// printf("col length/amt of rows: %d\n", data->rows);
	// printf("highest row index: %d\n", data->rows-1);
	// printf("row length/amt of columns: %d\n", data->columns);
	// printf("highest column index: %d\n", data->columns-1);
	while(data->map[0][++column])
	{
		if ((data->map[0][column] != '1')
			|| (data->map[data->rows-1][column] != '1'))
			{
				free_struct(data);
				error_msg("Horizontal wall should contain 1's only\n");
				exit(EXIT_FAILURE);
			}
	}
	// printf("loop for horizontal walls ended\ncolumn outside of range: %d\n\n", column);
	while(data->map[++row])
		if ((data->map[row][0] != '1')
			|| (data->map[row][data->columns-1] != '1'))
			{
				free_struct(data);
				error_msg("Vertical wall should contain 1's only\n");
				exit(EXIT_FAILURE);
			}
	// printf("loop for vertical walls ended\nrow outside of range: %d\n\n", row);
}

void	count_p_c_e(t_data *data)
{
	int	row;
	int	column;

	row = -1;
	while(data->map[++row])
	{
		column = -1;
		while(data->map[row][++column])
		{
			if (data->map[row][column] == 'P')
			{
				data->player++;
				// printf("P: %i\n", data->player); //printed an address at some point! WHY??
				data->player_row_pos = row;
				data->player_col_pos = column;
			}
			else if (data->map[row][column] == 'C')
			{
				data->collectible++;
				// printf("C: %i\n", data->collectible);
			}
			else if (data->map[row][column] == 'E')
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