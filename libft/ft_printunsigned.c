/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:53:51 by aeberius          #+#    #+#             */
/*   Updated: 2024/08/24 03:22:14 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_miniputnbr(unsigned int u, int *final_return);

void	ft_printunsigned(va_list args, int *final_return)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	ft_miniputnbr(u, final_return);
}

static void	ft_miniputnbr(unsigned int u, int *final_return)
{
	if (u >= 10)
		ft_miniputnbr(u / 10, final_return);
	ft_putchar(u % 10 + '0', final_return);
}
