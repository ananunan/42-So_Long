/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:21:34 by aeberius          #+#    #+#             */
/*   Updated: 2024/04/29 14:22:52 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (const char)c)
			count++;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	i = 0;
	while (count > 0)
	{
		if (s[i] == (const char)c)
			count--;
		if (count == 0)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
