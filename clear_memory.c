/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:59:51 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/04 13:35:04 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_images(t_data *data)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (data->img[i])
			mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}
	free(data->img);
}

void free_all(t_data *data)
{
	int i;

	if (data->img)
		free_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map_data)
	{
		i = 0;
		while (i < data->map_data->lines)
		{
			free(data->map_data->map[i]);
			free(data->map_data->dummy_map[i]);
			i++;
		}
		free(data->map_data->map);
		free(data->map_data->dummy_map);
		free(data->map_data);
	}
	if (data->content)
		free(data->content);
	free(data);
	exit(0);
}
