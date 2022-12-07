

#include "so_long.h"

//================================================ will be covered anyway later - easier to prevent
// map exists
// map >= 3 rows
// map >= 3 columns
//===============================================
// map has walls, collectible, free space
// map contains only 01CEP
// map contains 1 exit, 1 player
// map has >=1 collctible
// map is rectangular  
// map is surrounded by walls
// map should contain valid path (C and E should be reachable for P)
//===============================================

// void	check_upper_wall(t_data *data)
// {
// 		int	i;
// 	i = 0;
// 	while (data->map[0][i])
// 	{
// 		if (data->map[0][i++] != '1')
// 		{
// 			free_struct(data);
// 			error_msg("Upper map row should contain '1' only\n");
// 			exit(EXIT_FAILURE);
// 		}
// 	}
// }
void 	check_walls(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i++] != '1')
		{
			free_struct(data);
			error_msg("Upper map row should contain '1' only\n");
			exit(EXIT_FAILURE);
		}
	}
	// i = 0; //SEGFAULTTTTTTTTT
	// while (data->map[data->row][i]) // accessing -1 index
	// {
	// 	if (data->map[data->row][i++] != '1')
	// 	{
	// 		free_struct(data);
	// 		error_msg("Lower map row should contain '1' only");
	// 		exit(EXIT_FAILURE);
	// 	}
	// }

}

void	check_map(t_data *data)
{
	check_walls(data);
}	