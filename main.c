
#include "so_long.h"

typedef struct s_data
{
	char	**field;

} 				t_data;

void	dot_ber_check(char **av)
{
	int	i;

	i = ft_strlen(av[1]) - 1;
	if (av[1][i - 3] == '.' && av[1][i - 2] == 'b' \
		&& av[1][i - 1] == 'e' && av[1][i] == 'r')
		return ;
	else
	{
		write(2, "incorrect map format\n", 21);
		exit(EXIT_FAILURE);
	}
}

//checks:
//amt of arguments
//.ber format
void early_error_check(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "2 args needed\n", 14);
		exit(EXIT_FAILURE);
	}
	dot_ber_check(av);
}

// void	empty_init(t_data *data)
// {
	
// }

void	open_file(t_data *data, char **av) //./so_long ./maps/1.ber
{
	char	*line;
	int		fd;
	int		row = 0;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror(""); //free struct
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	// field[row] = ft_strtrim(line, '\n');



}

int main(int ac, char **av)
{
	t_data *data;

	early_error_check(ac, av);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	open_file(data, av);
}