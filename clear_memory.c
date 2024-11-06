/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:59:51 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/06 13:20:59 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->img[i])
			mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}
	free(data->img);
}

void	free_map_data(t_map_data *map_data)
{
	int	i;

	if (map_data)
	{
		i = 0;
		while (i < map_data->lines)
		{
			free(map_data->map[i]);
			free(map_data->dummy_map[i]);
			i++;
		}
		free(map_data->map);
		free(map_data->dummy_map);
		free(map_data);
	}
}

void	free_all(t_data *data)
{
	if (data->img)
		free_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_map_data(data->map_data);
	if (data->content)
		free(data->content);
	free(data);
	exit(0);
}
