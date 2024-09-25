/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:25:44 by aeberius          #+#    #+#             */
/*   Updated: 2024/08/24 03:22:00 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_ptohex(unsigned long p, int *final_return);

static void	ft_ptohex(unsigned long p, int *final_return)
{
	unsigned long	module;
	char			*ptr;

	ptr = "0123456789abcdef";
	if (p >= 16)
		ft_ptohex(p / 16, final_return);
	module = p % 16;
	write(1, &ptr[module], 1);
	*final_return = *final_return + 1;
}

void	ft_printpointer(va_list args, int *final_return)
{
	unsigned long	p;

	p = va_arg(args, unsigned long);
	if (p == 0)
	{
		write(1, "(nil)", 5);
		*final_return = *final_return + 5;
		return ;
	}
	ft_putchar('0', final_return);
	ft_putchar('x', final_return);
	ft_ptohex (p, final_return);
}
