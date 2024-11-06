/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:32:11 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/06 13:46:49 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_intro(t_data *data)
{
	int	width;
	int	height;

	width = 1920;
	height = 1080;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		print_error_menssage("Failed to initialize mlx\n", data);
	data->win = mlx_new_window(data->mlx, width, height, "Intro");
	if (data->win == NULL)
		print_error_menssage("Failed to create window\n", data);
	data->img = ft_calloc(1, sizeof(void *));
	if (data->img == NULL)
		print_error_menssage("Failed to allocate memory for images\n", data);
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "images/intro.xpm",
			&width, &height);
	if (data->img[0] == NULL)
		print_error_menssage("Failed to load image\n", data);
	mlx_put_image_to_window(data->mlx, data->win, data->img[0], 0, 0);
	mlx_hook(data->win, 2, 1L << 0, switch_to_main_window, data);
	mlx_loop(data->mlx);
}

void	show_end_image(t_data *data)
{
	int	width;
	int	height;

	width = 1920;
	height = 1080;
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	data->end_win = mlx_new_window(data->mlx, width, height,
			"Jigglypuff - Live at Cerulean City 2024 Full Concert");
	data->end_img = mlx_xpm_file_to_image(data->mlx, "images/end.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->end_win, data->end_img, 0, 0);
	mlx_hook(data->end_win, 2, 1L << 0, close_ending, data);
	mlx_loop(data->mlx);
}

int	switch_to_main_window(int keycode, t_data *data)
{
	(void)keycode;
	if (data->img[0])
	{
		mlx_destroy_image(data->mlx, data->img[0]);
		free(data->img);
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	graphics_initialize(data);
	return (0);
}

int	close_ending(int keycode, t_data *data)
{
	(void)keycode;
	if (data->end_img)
	{
		mlx_destroy_image(data->mlx, data->end_img);
		data->end_img = NULL;
	}
	if (data->end_win)
	{
		mlx_destroy_window(data->mlx, data->end_win);
		data->end_win = NULL;
	}
	free_all(data);
	return (0);
}

void	graphics_initialize(t_data *data)
{
	int	width;
	int	height;

	width = (data->map_data->columns) * 48;
	height = (data->map_data->lines) * 48;
	data->win = mlx_new_window(data->mlx, width, height,
			"Jigglypuff - Live at Cerulean City 2024 Full Concert");
	load_images(data);
	render_images(data, -1, -1);
	mlx_hook(data->win, 2, 1L << 0, keys_handler, data);
	mlx_hook(data->win, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx);
}
