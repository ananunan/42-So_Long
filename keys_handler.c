/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:58:55 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/06 14:15:08 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_position(t_data *data, int new_x, int new_y)
{
	int		old_x;
	int		old_y;
	char	new_pos;

	old_x = data->map_data->player_position[1];
	old_y = data->map_data->player_position[0];
	data->map_data->player_position[0] = new_y;
	data->map_data->player_position[1] = new_x;
	if (data->map_data->map[new_y][new_x] == 'C')
		data->content->collectible -= 1;
	if (old_y != new_y || old_x != new_x)
	{
		new_pos = data->map_data->map[new_y][new_x];
		data->map_data->map[old_y][old_x] = '0';
		data->map_data->map[new_y][new_x] = 'P';
		data->map_data->moves += 1;
		ft_printf("Moves: %d 🎤\n", data->map_data->moves);
		check_exit_and_update(data, new_pos);
	}
}

void	check_exit_and_update(t_data *data, char new_pos)
{
	if (data->map_data->map[data->map_data->exit_position[0]]
		[data->map_data->exit_position[1]] == '0')
	{
		data->map_data->map[data->map_data->exit_position[0]]
		[data->map_data->exit_position[1]] = 'E';
	}
	if (new_pos == 'E' && data->content->collectible == 0)
	{
		ft_printf("Ladies and gentlemen, please take your seats 🎤\n");
		show_end_image(data);
	}
}

void	move_player(int new_x, int new_y, t_data *data)
{
	if (data->map_data->map[new_y][new_x] != '1')
	{
		update_player_position(data, new_x, new_y);
	}
	render_images(data, -1, -1);
}

int	keys_handler(int keycode, t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->map_data->player_position[1];
	new_y = data->map_data->player_position[0];
	if (keycode == ESC)
		free_all(data);
	else if (keycode == UP_ARROW || keycode == W_KEY)
		new_y -= 1;
	else if (keycode == DOWN_ARROW || keycode == S_KEY)
		new_y += 1;
	else if (keycode == LEFT_ARROW || keycode == A_KEY)
	{
		new_x -= 1;
		data->player_img_index = 1;
	}
	else if (keycode == RIGHT_ARROW || keycode == D_KEY)
	{
		new_x += 1;
		data->player_img_index = 0;
	}
	move_player(new_x, new_y, data);
	return (0);
}
