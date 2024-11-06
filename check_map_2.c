/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:55 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/06 13:09:15 by aeberius         ###   ########.fr       */
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
	while (lines[i] != '\0' && lines[i] != '\n')
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
	data->map_data->dummy_map = ft_calloc(sizeof(char *),
			data->map_data->lines + 1);
	i = 0;
	lines = get_next_line(fd);
	while (lines != NULL)
	{
		data->map_data->map[i] = ft_strdup(lines);
		data->map_data->dummy_map[i] = ft_strdup(lines);
		free(lines);
		lines = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	check_map_content(char **map)
{
	int	i;
	int	g;

	i = 0;
	while (map[i] != NULL)
	{
		g = 0;
		while (map[i][g] != '\0')
		{
			if (map [i][g] != '1' && map[i][g] != '0' && map[i][g] != 'P'
				&& map[i][g] != 'C' && map[i][g] != 'E' && map[i][g] != '\n')
				return (0);
			g++;
		}
		i++;
	}
	return (1);
}

int	check_map_components(char **map, t_data *data)
{
	int	i;
	int	g;

	i = 0;
	while (map[i] != NULL)
	{
		g = 0;
		while (map[i][g] != '\0')
		{
			if (map[i][g] == 'P')
				data->content->player++;
			if (map[i][g] == 'C')
				data->content->collectible++;
			if (map[i][g] == 'E')
				data->content->exit++;
			g++;
		}
		i++;
	}
	if (data->content->player != 1 || data->content->collectible == 0
		|| data->content->exit != 1)
		return (0);
	return (1);
}
