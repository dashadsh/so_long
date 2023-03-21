/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangular_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:19:29 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:24:22 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
we check if map is rectangular,
example of non-rect map is:

111111111
10001
1
111

common mistake - square is a subversion of rectangle so square map should 
be considered as rectangular */
void	rectangular_check(t_data *data, char **av)
{
	int	fd;

	fd = open_file(data, av);
	rectangular_check2(data, fd);
	close(fd);
}

void	rectangular_check2(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i++ < (data->rows) - 1)
	{
		line = get_next_line(fd);
		if (data->columns != int_strlen(line) - 1)
		{
			free(line);
			close(fd);
			free_struct(data);
			error_msg_exit("Map should be rectangular\n");
		}
		free(line);
	}
	line = get_next_line(fd);
	if (data->columns != int_strlen(line))
	{
		free(line);
		close(fd);
		free_struct(data);
		error_msg_exit("Map should be bectangular\n");
	}
	free(line);
}
