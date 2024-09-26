/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:42:20 by aeberius          #+#    #+#             */
/*   Updated: 2024/09/26 12:14:39 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freesplits(char **splits)
{
	int	i;

	i = 0;
	if (splits != NULL)
	{
		while (splits[i] != NULL)
		{
			free(splits[i]);
			i++;
		}
	free(splits);
	}
}
