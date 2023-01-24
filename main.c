

#include "so_long.h"
//===================================================================================
// If any misconfiguration of any kind is encountered in the file, 
// the program must exit in a clean way, 
// and return "Error\n" followed by an explicit error message of your choice.
//===================================================================================

// void	zero_init(t_data *data)
// {
// 	// data->map = NULL;
// 	// data->duplicate = NULL;
// 	data->mlx_ptr = NULL;
// 	data->win_ptr = NULL;

// 	// data->win = NULL;
// 	data->rows = 0;
// 	data->columns = 0;
// 	data->player = 0;
// 	data->collectible = 0;
// 	data->exit = 0;

// 	data->row_pos = 0;
// 	data->col_pos = 0;

// 	// data->steps = 0;
// 	// data->collected = 0;
// 	data->wall_img = NULL;
// 	data->floor_img = NULL;
// 	data->collectible_img = NULL;
// 	data->exit_img = NULL;
// 	data->player_img = NULL;
// 	data->img_wh = 0;
// }

int main(int ac, char **av)
{
	t_data *data;

	early_error_check(ac, av);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
	{
		error_msg_exit("Couldn't malloc structure\n");
	}
	// zero_init(data);
	read_map(data, av); //read_map, check_map
	check_map(data);
	launch_graphics(data);

}
