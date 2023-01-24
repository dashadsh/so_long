

//======================================================================
// count_rows additionnly checks for: Empty file
//
// read_map additionally checks for: Map should be rectangular
//======================================================================
// when allocating map memory - should it be rows+1???
// change where is checked for row lenght  - can be done when counting rows
//======================================================================
// MKO
// ft_substr -> ft_strtrim
// needed for:
// count_rows & read_map
// possible to write new function to cut "\n" char an prevent memory leaks??

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

/* added check for row lenght here */
void	count_rows(t_data *data, char **av)
{
	int	fd;
	char	*line;

	fd = open_file(data, av);
	line = get_next_line(fd);
	if (line)
	{
		data->columns = ft_strlen(ft_strtrim(line, "\n"));
	}
 	else
	{
		free(data);
		error_msg("File is empty\n");
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		if (ft_strlen(ft_strtrim(line, "\n")) != data->columns)
		{
			free(data);
			error_msg("Map should be rectangular\n");
			exit(EXIT_FAILURE);
		}
		free(line); //why it should be freed here if i can free on the end??
		line = get_next_line(fd);
		data->rows++;
	}
	free(line); // - can freeing in a loop be really enough??
	if (data->rows < 3)
		{
			free(data);
			error_msg("At least 3 rows needed to build valid map\n");
			exit(EXIT_FAILURE);
		}
	close(fd);
}

/* allocates memory for the 2d map */
void 	allocate_map_memory(t_data *data)
{ // why calloc + 1 ???
	// data->map = ft_calloc(data->rows + 1, sizeof(char *)); 
	data->map = ft_calloc(data->rows + 1, sizeof(char *)); // alloc memory for 2d array - array or char pointers
	if (!data->map) 									   // otherwithe it will be: sizeof(char)
	// need to allocate +1 to set end of the map
	{
		free_struct(data);
		error_msg("Couldn't malloc data->map\n");
		exit(EXIT_FAILURE);
	}
}

void	read_map(t_data *data, char **av) // ./so_long ./maps/1.ber
{
	int		fd;
	char	*line;
	int		i = 0;

	fd = open_file(data, av);
	count_rows(data, av); // also adds data->row_length
	allocate_map_memory(data);
	line = get_next_line(fd);
	// // data->column was calculated before
	// // data->columns = ft_strlen(line) - 1;	// same as below
	// data->columns = ft_strlen(ft_strtrim(line, "\n")); // SIC - already done before
	while (line)
	{
		data->map[i] = ft_strtrim(line, "\n"); // add error check here?
		// printf("current row: %s\n", data->map[i]);
		free(line);
		line = get_next_line(fd); //GNL IS ALLOCATING MEMORY
		i++;
	}

	// printf("i: %d\n", i);
	// printf("row length: %d\n", data->row_length);

	// while (i--) // doublecheck for inv_small map please // MOVED IT TO ROW COUNTER
	// {
	// 	if (data->columns != ft_strlen(data->map[i]))
	// 	{
	// 		free_struct(data);
	// 		error_msg("Unsupported map shape\n");
	// 		exit(EXIT_FAILURE);
	// 	}	
	// }

	free(line);
	close(fd);
}
