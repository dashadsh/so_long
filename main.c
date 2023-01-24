

#include "so_long.h"
//===================================================================================
// If any misconfiguration of any kind is encountered in the file, 
// the program must exit in a clean way, 
// and return "Error\n" followed by an explicit error message of your choice.
//===================================================================================
/*
free 2d array of chars
*/
void	ft_clear(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

/*
free 2d array of ints
*/
void	ft_clear2(int **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_struct(t_data *data)
{
	if (data->map)
		ft_clear(data->map);
	if (data->duplicate)
		ft_clear2(data->duplicate);
}


int main(int ac, char **av)
{
	t_data *data;

	early_error_check(ac, av);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
	{
		error_msg("Couldn't malloc structure\n");
		exit(EXIT_FAILURE);
	}
	read_map(data, av); //read_map, check_map
	check_map(data);
	// free_struct(data);
	// run_window();
	launch_graphics(data);

}
