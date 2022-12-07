

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

void	simple_map_check(t_data *data)
{
	if (!data->map[0]) // !data->map is invalid - pointer EXISTS, but we're looking for starting char
	{
		free(data);
		error_msg("File is empty\n");
		exit(EXIT_FAILURE);
	}
	
}

void	check_map(t_data *data)
{
	simple_map_check(data);

}	