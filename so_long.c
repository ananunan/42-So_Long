/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:31:08 by aeberius          #+#    #+#             */
/*   Updated: 2024/09/26 12:57:14 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments ☜(꒡⌓꒡)\n");
		return (1);
	}
	else
	{
		if (check_map_extension(argv[1]) == 0)
			print_error_menssage("Map file must have .ber extension", NULL);
		if (check_map_file_exist(argv[1]) == 0)
			print_error_menssage("Map file does not exist", NULL);
		if (check_map_is_empty(argv[1]) == 0)
			print_error_menssage("Map file is empty", NULL);
		value_initialize(&data);
		count_lines(argv[1], data);
		count_columns(argv[1], data);
		extract_from_fd_to_map(argv[1], data);
		if (check_map_is_rectangular(data->map_data->map) == 0)
			print_error_menssage("Map is not rectangular", data);
		if (check_map_enclosed_by_walls(data->map_data->map, data) == 0)
			print_error_menssage("Map is not enclosed by walls", data);
		for(int i = 0; data->map_data->map[i] != NULL; i++)
			ft_printf("%s", data->map_data->map[i]);
		free_data(data);
	}
	return (0);
}

void	value_initialize(t_data **data)
{
	*data = malloc(sizeof(t_data));
	(*data)->map_data = malloc(sizeof(t_map_data));
	(*data)->map_data->lines = 0;
	(*data)->map_data->columns = 0;
	(*data)->map_data->map = NULL;
}

void	print_error_menssage(char *menssage, t_data *data)
{
	ft_printf("Error\n%s ☜(꒡⌓꒡)\n", menssage);
	free_data(data);
	exit(1);
}

void	free_data(t_data *data)
{
	if (data != NULL)
	{
		if (data->map_data != NULL)
		{
			if (data->map_data->map != NULL)
				ft_freesplits(data->map_data->map);
			free(data->map_data);
		}
		free(data);
	}
}
