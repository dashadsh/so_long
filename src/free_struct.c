/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:04:32 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:23:35 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
free 2d array of chars

not sure if i need (str = NULL;) on the end of the function
*/
void	ft_clear_2d_chars(char **str)
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

not sure if i need (str = NULL;) on the end of the function
*/
void	ft_clear_2d_ints(int **str)
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
i added now:

if (!data)
	return ;
*/
void	free_struct(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		ft_clear_2d_chars(data->map);
	if (data->duplicate)
		ft_clear_2d_ints(data->duplicate);
	free(data);
}
