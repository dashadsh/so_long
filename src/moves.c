/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:05:45 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:31:05 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_new_map(t_data *data)
{
	create_map(data);
	display_steps(data);
}

/* when we are moving towards EXIT field and ther eare no collectibles
left on the map we can exit the game

i exit it immidiately - couldn't figure out how to add "winning image"
and stay longer on a map

when we didnt collet all yet we can step on the exit - 
we save that img and put it again on the field when we leave exit

if we have left the place with C we put there img 0
that s why we need last_positio in our structure

map is being updated
and after each step we render a new map COMPLETELY
*/
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
