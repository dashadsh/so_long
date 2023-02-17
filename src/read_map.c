/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:06:28 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:26:46 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
we should open file again to use GNL, 
because we should read again from the start

don't forget - GNL allocates memory
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

/* 
why there should be free in a loop 
can freeing in a loop be really enough??
*/
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

/*
smallest map could look like:
11111
1PCE1
11111

i also could have added this check for columns...
*/

void	tiny_map_error_check(t_data *data)
{
	if (data->rows < 3)
	{
		free_struct(data);
		error_msg_exit("Min. 3 rows needed to build a map\n");
	}
}

/* 
allocates memory for the 2d map:
array or char pointers
otherwithe it will be: sizeof(char)

not sure if i need to allocate +1
*/
void	allocate_map_memory(t_data *data, int fd)
{
	data->map = ft_calloc(data->rows + 1, sizeof(char *));
	if (!data->map)
	{
		free_struct(data);
		close(fd);
		error_msg_exit("Couldn't malloc data->map\n");
	}
}

/*
we need to open and close fd several time to be able to read
from the start of the file


i think it could be also added error check for strtrim
*/
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
		data->map[i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}
