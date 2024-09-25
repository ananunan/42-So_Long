/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:40:42 by aeberius          #+#    #+#             */
/*   Updated: 2024/08/24 03:21:47 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_checkpercent(va_list args, const char *format,
				int *final_return);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		final_return;

	final_return = 0;
	va_start(args, format);
	ft_checkpercent (args, format, &final_return);
	va_end (args);
	return (final_return);
}

static void	ft_checkpercent(va_list args, const char *format, int *final_return)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_printchar(args, final_return);
			if (*format == 's')
				ft_printstring(args, final_return);
			if (*format == 'p')
				ft_printpointer(args, final_return);
			if (*format == 'd' || *format == 'i')
				ft_printdigits(args, final_return);
			if (*format == 'u')
				ft_printunsigned(args, final_return);
			if (*format == 'x' || *format == 'X')
				ft_printhex(args, *format, final_return);
			if (*format == '%')
				ft_putchar('%', final_return);
		}
		else
			ft_putchar(*format, final_return);
		format++;
	}
}
