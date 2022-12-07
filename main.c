#include "so_long.h"

typedef struct s_data
{
	char	**map;
	int		row;
} 				t_data;

void	ft_clear(char **str);
void	free_struct(t_data *data);
void	dot_ber_check(char **av);
void 	early_error_check(int ac, char **av);
int		open_file(t_data *data, char **av);
void	count_rows(t_data *data, char **av);
void 	allocate_map_memory(t_data *data);
void	read_map(t_data *data, char **av);
int 	main(int ac, char **av);

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

void	free_struct(t_data *data)
{
	if (data->map)
		ft_clear(data->map);
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
		write(2, "incorrect map format\n", 21);
		exit(EXIT_FAILURE);
	}
}

void early_error_check(int ac, char **av) //no malloc's yet
{
	if (ac != 2)
	{
		write(2, "2 args needed\n", 14);
		exit(EXIT_FAILURE);
	}
	dot_ber_check(av);
}

int	open_file(t_data *data, char **av)
{
	int fd; // we should open file again to use GNL, because we should read again from the start

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		free_struct(data);
		perror("");
		exit(EXIT_FAILURE);
	}
	return(fd);
}

void	count_rows(t_data *data, char **av)
{
	int fd;
	char	*line;

	fd = open_file(data, av);
	line = get_next_line(fd);
	while (line)
	{
		free(line); //why it should be freed here if i can free on the end??
		line = get_next_line(fd);
		data->row++;
	}
	// free(line); - can freeing in a loop be really enough??
	close(fd);
}

void 	allocate_map_memory(t_data *data)
{
	data->map = ft_calloc(data->row + 1, sizeof(char *)); // alloc memory for 2d array - array or char pointers
	if (!data->map)
	{
		perror("couldn't allocate memory for data->map");
		free_struct(data);
		exit(EXIT_FAILURE);
	}
}

void	read_map(t_data *data, char **av) // ./so_long ./maps/1.ber
{
	int		fd;
	char	*line;
	int		i = 0;

	fd = open_file(data, av);
	count_rows(data, av);
	allocate_map_memory(data);
	line = get_next_line(fd);
	while (line)
	{
		data->map[i] = ft_strtrim(line, "\n");
		// printf("row %d: %s\n", i, data->map[i]);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	// free(line);
	close(fd);
}

int main(int ac, char **av)
{
	t_data *data;

	early_error_check(ac, av);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	read_map(data, av); //read_map, check_map
	free_struct(data);
}