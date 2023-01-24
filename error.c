

#include "so_long.h"

void error_msg(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
}

void error_msg_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void error_msg_free_exit(char *msg, t_data *data)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	free_struct(data);
	exit(EXIT_FAILURE);
}