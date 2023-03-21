/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   early_error_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:19:44 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:13:40 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
early errors check
so no memory allocation happens if error is chatched
at that stage
*/
#include "../so_long.h"

void	dot_ber_check(char **av)
{
	int	i;

	i = ft_strlen(av[1]) - 1;
	if (av[1][i - 3] == '.' && av[1][i - 2] == 'b' \
		&& av[1][i - 1] == 'e' && av[1][i] == 'r')
		return ;
	else
	{
		error_msg_exit("Incorrect map format, should be .ber\n");
	}
}

void	early_error_check(int ac, char **av)
{
	if (ac != 2)
	{
		error_msg_exit("Wrong amount of arguments, try: ./so_long map.ber\n");
	}
	dot_ber_check(av);
}
