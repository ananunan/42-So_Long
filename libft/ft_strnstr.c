/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:21:40 by aeberius          #+#    #+#             */
/*   Updated: 2024/04/24 15:24:11 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (big[i] != '\0' && i < len)
	{
		if (ft_strncmp(&big[i], little, little_len) == 0
			&& i + little_len <= len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
