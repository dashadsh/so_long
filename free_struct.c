/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:04:32 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/01/26 11:08:45 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
free 2d array of chars

?? 	// str = NULL;
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
}

/*
free 2d array of ints
?? 	// str = NULL;
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
}

void	free_struct(t_data *data)
{
	if (data->map)
		ft_clear(data->map);
	if (data->duplicate)
		ft_clear2(data->duplicate);
	// if (data->mlx_ptr)
	// 	free(data->mlx_ptr);
	// if (data->win_ptr)
	// 	free(data->win_ptr);
	// void	*floor_img;
	// void	*wall_img;
	// void	*player_img;
	// void	*collectible_img;
	// void	*exit_img;
	// void	*exit_open_img;
	free(data);
}
