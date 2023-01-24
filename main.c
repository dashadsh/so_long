

#include "so_long.h"
//===================================================================================
// If any misconfiguration of any kind is encountered in the file, 
// the program must exit in a clean way, 
// and return "Error\n" followed by an explicit error message of your choice.
//===================================================================================
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

void	dot_ber_check(char **av)
{
	int	i;

	i = ft_strlen(av[1]) - 1;
	if (av[1][i - 3] == '.' && av[1][i - 2] == 'b' \
		&& av[1][i - 1] == 'e' && av[1][i] == 'r')
		return ;
	else
	{
		error_msg("Incorrect map format, should be .ber\n");
		exit(EXIT_FAILURE);
	}
}

void	early_error_check(int ac, char **av) //no malloc's yet
{
	if (ac != 2)
	{
		error_msg("Wrong amount of arguments, try: ./so_long map.ber\n");
		exit(EXIT_FAILURE);
	}
	dot_ber_check(av);
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
	check_valid_path(data);
	// free_struct(data);
	// run_window();
	launch_graphics(data);

}
