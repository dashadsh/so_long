
//======================================================================
// count_rows additionnly checks for: Empty file
//
// read_map additionally checks for: Map should be rectangular
//======================================================================

#include "so_long.h"

int	open_file(t_data *data, char **av)
{
	int fd; // we should open file again to use GNL, because we should read again from the start

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		free_struct(data);
		error_msg("Couldn't open the file\n");
		exit(EXIT_FAILURE);
	}
	return(fd);
}

// void	count_row_length(t_data *data, char **av)
// {
// 	int		fd;
// 	char	*line;
// 	fd = open(av[1], O_RDONLY);
// 	line = get_next_line(fd);
// 	data->row_length = ft_strlen(line) - 1;
// 	printf("row lengh: %d\n", data->row_length);
// 	free(line);
// 	close(fd);
// }

void	count_rows(t_data *data, char **av)
{
	int	fd;
	char	*line;

	fd = open_file(data, av);
	line = get_next_line(fd);
	if (line)
		data->row_length = ft_strlen(line) - 1; // will work with non empty file only
 	else
	{
		free(data);
		error_msg("File is empty\n");
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		free(line); //why it should be freed here if i can free on the end??
		line = get_next_line(fd);
		data->row++;
	}
	free(line); // - can freeing in a loop be really enough??
	close(fd);
}

void 	allocate_map_memory(t_data *data)
{
	data->map = ft_calloc(data->row + 1, sizeof(char *)); // alloc memory for 2d array - array or char pointers
	if (!data->map)
	{
		free_struct(data);
		error_msg("Couldn't malloc data->map\n");
		exit(EXIT_FAILURE);
	}
}

// also adds data->row_length
void	read_map(t_data *data, char **av) // ./so_long ./maps/1.ber
{
	int		fd;
	char	*line;
	int		i = 0;

	fd = open_file(data, av);
	count_rows(data, av);
	allocate_map_memory(data);
	line = get_next_line(fd);
	data->row_length = ft_strlen(line) - 1;	// same as below
	// data->row_length = ft_strlen(ft_strtrim(line, "\n"));	
	while (line)
	{
		data->map[i] = ft_strtrim(line, "\n"); // add error check here?
		// printf("current row: %s\n", data->map[i]);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	// printf("i: %d\n", i);
	// printf("row length: %d\n", data->row_length);
	while (i--) // doublecheck please!
	{
		if (data->row_length != ft_strlen(data->map[i]))
		{
			free_struct(data);
			error_msg("Map should be rectangular\n");
			exit(EXIT_FAILURE);
		}	
	}
	free(line);
	close(fd);
}
