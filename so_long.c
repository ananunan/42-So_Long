/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:31:08 by aeberius          #+#    #+#             */
/*   Updated: 2024/09/25 15:57:16 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments ☜(꒡⌓꒡)\n");
		return (1);
	}
	else
	{
		if (check_map_extension(argv[1]) == 0)
			ft_printf("Error\nMap file is not a .ber file ☜(꒡⌓꒡)\n");
		else if (check_map_file_exist(argv[1]) == 0)
			ft_printf("Error\nMap file does not exist ☜(꒡⌓꒡)\n");
		else
		{
			data = (t_data *)malloc(sizeof(t_data));
			if (data == NULL)
				return (1);
			data->map_data = (t_map_data *)malloc(sizeof(t_map_data));
			if (data->map_data == NULL)
				return (1);
			fd = open(argv[1], O_RDONLY);
			count_lines(fd, data);
			fd = open(argv[1], O_RDONLY);
			extract_from_fd_to_map(fd, data);
			for(int i = 0; data->map_data->map[i] != NULL; i++)
				ft_printf("%s", data->map_data->map[i]);
		}
	}
	return (0);
}

