#include "so_long.h"

void	display_steps(t_data *data)
{
	char	*steps;

	steps = ft_itoa(data->steps);
	ft_putstr_fd("steps: ", 1);
	ft_putstr_fd(steps, 1);
	ft_putstr_fd("\n", 1);
	free(steps);
}

// void	is_exit(t_data *data, int row, int col)
// {
// 	if (data->collectible != data->collected)
// 	{
// 		ft_printf("mouse must fight with all cats first\n");
// 		change_position(data, row, col);
// 	}
// 	else
// 	{
// 		ft_printf("you won!\n");
// 		// free_destroy(data);
// 	}
// }