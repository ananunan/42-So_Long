/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:11:35 by aeberius          #+#    #+#             */
/*   Updated: 2024/04/29 15:07:40 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;
	size_t			i;

	i = 0;
	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	while (i < size * nmemb)
	{
		result[i++] = '\0';
	}
	return (result);
}
