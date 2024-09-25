/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:01:06 by aeberius          #+#    #+#             */
/*   Updated: 2024/04/24 15:25:37 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*fd = 0 entrada dados \ fd = 1 imprimir \ fd = 2 error;*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
