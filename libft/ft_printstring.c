/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:51:52 by aeberius          #+#    #+#             */
/*   Updated: 2024/08/24 03:22:06 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstring(va_list args, int *final_return)
{
	int		i;
	char	*s;

	i = 0;
	s = va_arg(args, char *);
	if (s == NULL)
	{
		write (1, "(null)", 6);
		*final_return = *final_return + 6;
		return ;
	}
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	*final_return = *final_return + i;
}
