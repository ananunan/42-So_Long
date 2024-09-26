/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:30:15 by aeberius          #+#    #+#             */
/*   Updated: 2024/09/26 12:56:58 by aeberius         ###   ########.fr       */
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

typedef struct s_map_data
{
	int		lines;
	int		columns;
	char	**map;
}			t_map_data;

typedef struct s_data
{
	t_map_data	*map_data;
}			t_data;

int		check_map_is_empty(char *argv);
int		check_map_extension(char *filename);
int		check_map_file_exist(char *filename);
int		check_map_is_rectangular(char **map);
int		check_map_enclosed_by_walls(char **map, t_data *data);

void	free_data(t_data *data);
void	value_initialize(t_data **data);
void	count_lines(char *argv, t_data *data);
void	count_columns(char *argv, t_data *data);
void	extract_from_fd_to_map(char *argv, t_data *data);
void	print_error_menssage(char *menssage, t_data *data);

#endif
