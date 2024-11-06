/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:03:49 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/06 13:09:07 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *argv)
{
	if (check_file_extension(argv) == 0)
		print_error_menssage("Map file must have .ber extension", NULL);
	if (check_file_exist(argv) == 0)
		print_error_menssage("Map file does not exist", NULL);
	if (check_file_is_empty(argv) == 0)
		print_error_menssage("Map file is empty", NULL);
}

void	check_map(t_data *data)
{
	if (check_map_is_rectangular(data->map_data->map) == 0)
		print_error_menssage("Map is not rectangular", data);
	if (check_map_enclosed_by_walls(data->map_data->map, data) == 0)
		print_error_menssage("Map is not enclosed by walls", data);
	if (check_map_content(data->map_data->map) == 0)
		print_error_menssage("Map has invalid characters", data);
	if (check_map_components(data->map_data->map, data) == 0)
		print_error_menssage("Map has invalid components", data);
}

void	check_utils(char *argv, t_data *data)
{
	count_lines(argv, data);
	count_columns(argv, data);
	extract_from_fd_to_map(argv, data);
	check_map(data);
	find_player_and_exit_position(data->map_data->map, data);
	flood_fill(data->map_data->dummy_map, data->map_data->player_position[0],
		data->map_data->player_position[1], data);
	if (check_dummy_map(data->map_data->dummy_map) == 0)
		print_error_menssage("Map has invalid path", data);
}
