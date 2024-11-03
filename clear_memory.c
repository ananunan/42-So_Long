/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:59:51 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/03 16:27:10 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *data)
{
	if (data != NULL)
	{
		if (data->map_data != NULL)
		{
			if (data->map_data->map != NULL)
				ft_freesplits(data->map_data->map);
			if (data->map_data->dummy_map != NULL)
				ft_freesplits(data->map_data->dummy_map);
			free(data->map_data);
		}
		if (data->content != NULL)
			free(data->content);
		free(data);
	}
}

void	free_mlx(t_data *data)

{
	if (data != NULL)
	{
		if (data->mlx != NULL)
			mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
	}
}
/*
void	free_img(t_img *img)
{
	if (img != NULL)
	{
		if (img->img != NULL)
			mlx_destroy_image(img->mlx, img->img);
	}
}*/

void	free_all(t_data *data)
{

	free_mlx(data);
	free_data(data);
	exit(1);
	//free_img(img);
}
