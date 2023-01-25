

#include "so_long.h"

void	dot_ber_check(char **av)
{
	int	i;

	i = ft_strlen(av[1]) - 1;
	if (av[1][i - 3] == '.' && av[1][i - 2] == 'b' \
		&& av[1][i - 1] == 'e' && av[1][i] == 'r')
		return ;
	else
	{
		error_msg_exit("Incorrect map format, should be .ber\n");
	}
}

void	early_error_check(int ac, char **av)
{
	if (ac != 2)
	{
		error_msg_exit("Wrong amount of arguments, try: ./so_long map.ber\n");
	}
	dot_ber_check(av);
}