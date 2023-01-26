/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:36:45 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/01/26 11:57:59 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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