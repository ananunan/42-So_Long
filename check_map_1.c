/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:36:25 by aeberius          #+#    #+#             */
/*   Updated: 2024/09/25 13:13:06 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_file_exist(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_map_extension(char *filename)
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

int	check_map_is_rectangular(char **map)
{
	int	i;
	int	g;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		g = 0;
		while (map[i][g] != '\0')
			g++;
		if (g != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_map_is_empty(char **map)
{
	int	i;
	int	g;

	i = 0;
	while (map[i] != NULL)
	{
		g = 0;
		while (map[i][g] != '\0')
		{
			if (map[i][g] != '1' && map[i][g] != '0' && map[i][g] != 'P'
				&& map[i][g] != 'E' && map[i][g] != 'C')
				return (0);
			g++;
		}
		i++;
	}
	return (1);
}

int	check_map_enclosed_in_walls(char **map)
{
	int	i;
	int	g;

	i = 0;
	while (map[i] != NULL)
	{
		// falta verificar se a primeira e ultima linha sao 1
		g = 0;
		i++;
		while (map[i][g] != '\0')
		{
			g++;
			if (map[i - 1][g - 1] != '1' || map[i][g - 1] != '1'
				|| map[i - 1][0] != '1' || map[i - 1][g] != '1')
				return (0);
		}
	}
	return (1);
}
