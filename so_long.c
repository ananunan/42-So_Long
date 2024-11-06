/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:31:08 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/06 13:14:42 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		print_error_menssage("Invalid number of arguments\n", NULL);
		return (1);
	}
	else
	{
		check_file(argv[1]);
		value_initialize(&data);
		check_utils(argv[1], data);
		show_intro(data);
		free_all(data);
	}
	return (0);
}

void	value_initialize(t_data **data)
{
	*data = ft_calloc(sizeof(t_data), 1);
	(*data)->map_data = ft_calloc(sizeof(t_map_data), 1);
	(*data)->content = ft_calloc(sizeof(t_content), 1);
	(*data)->content->player = 0;
	(*data)->content->collectible = 0;
	(*data)->content->exit = 0;
	(*data)->map_data->lines = 0;
	(*data)->map_data->columns = 0;
	(*data)->map_data->map = NULL;
	(*data)->map_data->player_position[0] = 0;
	(*data)->map_data->player_position[1] = 0;
	(*data)->map_data->moves = 0;
}

void	print_error_menssage(char *menssage, t_data *data)
{
	ft_printf("Error\n%s ☜(꒡⌓꒡)\n", menssage);
	if (data != NULL)
		free_all(data);
	exit(1);
}
