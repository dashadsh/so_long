/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:05:28 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/01/25 21:05:32 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_steps(t_data *data)
{
	char	*steps;

	steps = ft_itoa(data->steps);
	ft_putstr_fd("steps: ", 1);
	ft_putstr_fd(steps, 1);
	ft_putstr_fd("\n", 1);
	free(steps);
}
