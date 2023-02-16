/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:05:45 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/16 15:30:55 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_d(t_data *data)
{
	if (data->map[data->row_pos][data->col_pos + 1] == '1')
		return ;
	if (data->map[data->row_pos][data->col_pos + 1] == 'E' &&
		!is_c(data))
	{
		finish_the_game(data);
	}
	data->steps++;
	if (data->last_pos == 'C')
			data->last_pos = '0';
	data->map[data->row_pos][data->col_pos] = data->last_pos;
	data->last_pos = data->map[data->row_pos][data->col_pos + 1];
	data->map[data->row_pos][data->col_pos + 1] = 'P';
	create_new_map(data);
	data->col_pos++;
}

void	move_a(t_data *data)
{
	if (data->map[data->row_pos][data->col_pos - 1] == '1')
		return ;
	if (data->map[data->row_pos][data->col_pos - 1] == 'E' &&
		!is_c(data))
	{
		finish_the_game(data);
	}
	data->steps++;
	if (data->last_pos == 'C')
			data->last_pos = '0';
	data->map[data->row_pos][data->col_pos] = data->last_pos;
	data->last_pos = data->map[data->row_pos][data->col_pos - 1];
	data->map[data->row_pos][data->col_pos - 1] = 'P';
	create_new_map(data);
	data->col_pos--;
}

void	move_w(t_data *data)
{
	if (data->map[data->row_pos - 1][data->col_pos] == '1')
		return ;
	if (data->map[data->row_pos - 1][data->col_pos] == 'E' &&
		!is_c(data))
	{
		finish_the_game(data);
	}
	data->steps++;
	if (data->last_pos == 'C')
			data->last_pos = '0';
	data->map[data->row_pos][data->col_pos] = data->last_pos;
	data->last_pos = data->map[data->row_pos - 1][data->col_pos];
	data->map[data->row_pos - 1][data->col_pos] = 'P';
	create_new_map(data);
	data->row_pos--;
}

void	move_s(t_data *data)
{
	if (data->map[data->row_pos + 1][data->col_pos] == '1')
		return ;
	if (data->map[data->row_pos + 1][data->col_pos] == 'E' &&
		!is_c(data))
	{
		finish_the_game(data);
	}
	data->steps++;
	if (data->last_pos == 'C')
			data->last_pos = '0';
	data->map[data->row_pos][data->col_pos] = data->last_pos;
	data->last_pos = data->map[data->row_pos + 1][data->col_pos];
	data->map[data->row_pos + 1][data->col_pos] = 'P';
	create_new_map(data);
	data->row_pos++;
}
