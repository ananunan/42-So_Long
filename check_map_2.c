/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:55 by aeberius          #+#    #+#             */
/*   Updated: 2024/09/26 12:20:20 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_lines(char *argv, t_data *data)
{
	char	*lines;
	int		fd;

	fd = open(argv, O_RDONLY);
	lines = get_next_line(fd);
	while (lines != NULL)
	{
		data->map_data->lines++;
		free(lines);
		lines = get_next_line(fd);
	}
	close(fd);
}

void	count_columns(char *argv, t_data *data)
{
	char	*lines;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	lines = get_next_line(fd);
	i = 0;
	while (lines[i] != '\0')
	{
		data->map_data->columns++;
		i++;
	}
	while (lines != NULL)
	{
		free(lines);
		lines = get_next_line(fd);
	}
	close(fd);
}

void	extract_from_fd_to_map(char *argv, t_data *data)
{
	char	*lines;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	data->map_data->map = ft_calloc(sizeof(char *), data->map_data->lines + 1);
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
