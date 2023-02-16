/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:06:28 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/16 15:32:14 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// when allocating map memory - should it be rows+1???
// change where is checked for row lenght  - can be done when counting rows
//======================================================================
// MKO
// ft_substr -> ft_strtrim
// needed for:
// count_rows & read_map
// possible to write new function to cut "\n" char an prevent memory leaks??

#include "so_long.h"

/*
we should open file again to use GNL, 
because we should read again from the start

free(data); is enough here
*/
int	open_file(t_data *data, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		free_struct(data);
		error_msg_exit("Couldn't open the file\n");
	}
	return (fd);
}

/* why there should be free in a loop 
can freeing in a loop be really enough??*/
void	count_col_rows(t_data *data, char **av)
{
	int		fd;
	char	*line;

	fd = open_file(data, av);
	line = get_next_line(fd);
	if (line)
		data->columns = int_strlen(line) - 1;
	else
	{
		free_struct(data);
		error_msg_exit("File is empty\n");
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->rows++;
	}
	free(line);
	close(fd);
	tiny_map_error_check(data);
}

void	tiny_map_error_check(t_data *data)
{
	if (data->rows < 3)
	{
		free_struct(data);
		error_msg_exit("Min. 3 rows needed to build a map\n"); //	free(data);
	}
}

/* 
allocates memory for the 2d map:
array or char pointers
otherwithe it will be: sizeof(char)

????????? calloc + 1?? need to allocate +1 to set end of the map ??
*/
void	allocate_map_memory(t_data *data, int fd)
{
	data->map = ft_calloc(data->rows + 1, sizeof(char *));
	if (!data->map)
	{
		free_struct(data);
		close(fd);
		error_msg_exit("Couldn't malloc data->map\n"); //free_struct(data);
	}
}

void	read_map(t_data *data, char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	count_col_rows(data, av);
	rectangular_check(data, av);
	fd = open_file(data, av);
	allocate_map_memory(data, fd);
	line = get_next_line(fd);
	while (line)
	{
		data->map[i] = ft_strtrim(line, "\n"); // add error check here?
		free(line);
		line = get_next_line(fd); //GNL IS ALLOCATING MEMORY
		i++;
	}
	free(line);
	close(fd);
}
