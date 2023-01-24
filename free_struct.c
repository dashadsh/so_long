
#include "so_long.h"

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
	// str = NULL;
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
	// str = NULL;
}

void	free_struct(t_data *data)
{
	if (data->map)
		ft_clear(data->map);
	if (data->duplicate)
		ft_clear2(data->duplicate);
	free(data);
}
