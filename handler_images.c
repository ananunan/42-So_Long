/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:29:53 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/03 17:24:00 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_data *data)
{
	int	i;

	data->img = ft_calloc(sizeof(void *) , 5);
	i = 48;
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "images/player.xpm",
			&i, &i);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "images/collectible.xpm",
			&i, &i);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm",
			&i, &i);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm",
			&i, &i);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "images/floor.xpm",
			&i, &i);
}

void	render_images(t_data *data, int i, int g)
{
	while (++i < data->map_data->lines)
	{
		g = -1;
		while (++g < data->map_data->columns)
		{
			if (data->map_data->map[i][g] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img[3],
					g * 48, i * 48);
			else if (data->map_data->map[i][g] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img[4],
					g * 48, i * 48);
			else if (data->map_data->map[i][g] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img[0],
					g * 48, i * 48);
			else if (data->map_data->map[i][g] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img[1],
					g * 48, i * 48);
			else if (data->map_data->map[i][g] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img[2],
					g * 48, i * 48);
		}
	}
}
