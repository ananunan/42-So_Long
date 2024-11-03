/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:32:11 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/03 17:48:41 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graphics_initialize(t_data *data)
{
	int	length;
	int	height;

	length = (data->map_data->columns -1)* 48;
	height = data->map_data->lines * 48;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, length,
		height, "Jigglypuff - Live at Cerulean City 2024 Full Concert (8-bit Quality)");
	mlx_hook(data->win, 2, 1L << 0, keys_handler, data);
	load_images(data);
	render_images(data, -1, -1);
	mlx_loop(data->mlx);
	mlx_loop_end(data->mlx);
}
