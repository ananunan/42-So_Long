/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:15:23 by aeberius          #+#    #+#             */
/*   Updated: 2024/08/24 03:21:20 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printchar(va_list args, int *final_return)
{
	char	c;

	c = va_arg(args, int);
	write (1, &c, 1);
	*final_return = *final_return + 1;
}
