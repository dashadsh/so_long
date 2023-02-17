/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:50:25 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/02/17 20:13:44 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* different error messages depend on
if we need to free memory or not

1. could be solved differently by changing free_struct(data)
adding if (!data) return

2.defining errors could be done in header file
adding one function to cover all error cases
*/
void	error_msg(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
}

void	error_msg_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	error_msg_free_exit(char *msg, t_data *data)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	free_struct(data);
	exit(EXIT_FAILURE);
}
