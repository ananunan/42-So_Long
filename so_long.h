/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:30:15 by aeberius          #+#    #+#             */
/*   Updated: 2024/11/04 16:04:05 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

// Key Code
# define ESC 65307
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361
# define UP_ARROW 65362
# define DOWN_ARROW 65364

typedef struct s_map_data
{
	int		lines;
	int		columns;
	int		player_position[2];
	int		exit_position[2];
	int		moves;
	char	**map;
	char	**dummy_map;
}			t_map_data;

typedef struct s_content
{
	int		player;
	int		collectible;
	int		exit;
}			t_content;

typedef struct s_data
{
	t_map_data	*map_data;
	t_content	*content;
	void		*mlx;
	void		*win;
	void		*end_img;
	void		*end_win;
	void		**img;
	int			player_img_index;
}			t_data;

int close_ending(int keycode, t_data *data);
int		close_window(t_data *data);
int		check_dummy_map(char **map);
int		check_map_content(char **map);
int		check_file_is_empty(char *argv);
int		check_file_exist(char *filename);
int		check_file_extension(char *filename);
int		check_map_is_rectangular(char **map);
int		keys_handler(int keycode, t_data *data);
int		check_map_components(char **map, t_data *data);
int		switch_to_main_window(int keycode, t_data *data);
int		check_map_enclosed_by_walls(char **map, t_data *data);

void	free_all(t_data *data);
void	check_file(char *argv);
void	check_map(t_data *data);
void	show_intro(t_data *data);
void	load_images(t_data *data);
void	show_end_image(t_data *data);
void	value_initialize(t_data **data);
void	graphics_initialize(t_data *data);
void	count_lines(char *argv, t_data *data);
void	check_utils(char *argv, t_data *data);
void	count_columns(char *argv, t_data *data);
void	render_images(t_data *data, int i, int g);
void	move_player(int new_x, int new_y, t_data *data);
void	extract_from_fd_to_map(char *argv, t_data *data);
void	print_error_menssage(char *menssage, t_data *data);
void	flood_fill(char **map, int i, int g, t_data *data);
void	find_player_and_exit_position(char **map, t_data *data);

#endif


