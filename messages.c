


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
