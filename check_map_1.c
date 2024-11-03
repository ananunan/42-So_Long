/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:36:25 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/03 16:18:26 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_exist(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_file_extension(char *filename)
{
	int	i;

	i = 0;
	while (filename[i] != '\0')
		i++;
	if (filename[i - 1] == 'r' && filename[i - 2] == 'e'
		&& filename[i - 3] == 'b' && filename[i - 4] == '.')
		return (1);
	return (0);
}

int	check_file_is_empty(char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		free(line);
		return (0);
	}
	close(fd);
	free(line);
	return (1);
}

int	check_map_is_rectangular(char **map)
{
	int				i;
	size_t			g;
	size_t			len;

	i = 0;
	len = ft_strlen(map[0]) - 1;
	while (map[i] != NULL)
	{
		g = 0;
		while (map[i][g] != '\0' && map[i][g] != '\n' && map[i][g] != ' ')
			g++;
		if (g != len)
			return (0);
		i++;
	}
	if (i == 1)
		return (0);
	return (1);
}

int	check_map_enclosed_by_walls(char **map, t_data *data)
{
	int	i;
	int	g;

	i = 0;
	while (map[i] != NULL)
	{
		g = 0;
		if (i == 0 || i == data->map_data->lines - 1)
		{
			while (map[i][g] != '\0')
			{
				if (map[i][g] != '1' && map[i][g] != '\n')
					return (0);
				g++;
			}
		}
		else
		{
			if (map[i][0] != '1' || map[i][data->map_data->columns - 2] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}
