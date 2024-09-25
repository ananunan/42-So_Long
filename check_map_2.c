/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:55 by aeberius          #+#    #+#             */
/*   Updated: 2024/09/25 15:57:55 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void count_lines(int fd, t_data *data)
{
	char	*lines;

	data->map_data->lines = 0;
	lines = get_next_line(fd);
	while (lines != NULL)
	{
		data->map_data->lines++;
		free(lines);
		lines = get_next_line(fd);
	}
	close(fd);
}
void count_columns(int fd, t_data *data)
{
	char	*lines;
	int		i;

	data->map_data->columns = 0;
	lines = get_next_line(fd);
	i = 0;
	while (lines[i] != '\0')
	{
		data->map_data->columns++;
		i++;
	}
	free(lines);
}
void extract_from_fd_to_map(int fd, t_data *data)
{
	char	*lines;
	int		i;

	data->map_data->map = (char **)malloc(sizeof(char *) * data->map_data->lines);
	i = 0;
	lines = get_next_line(fd);
	while (lines != NULL)
	{
		data->map_data->map[i] = ft_strdup(lines);
		free(lines);
		lines = get_next_line(fd);
		i++;
	}
	close(fd);
}
