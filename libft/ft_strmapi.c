/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:14:00 by aeberius          #+#    #+#             */
/*   Updated: 2024/04/25 12:46:32 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str_calloc;

	i = 0;
	str_calloc = ft_calloc (sizeof(char), ft_strlen(s) + 1);
	if (str_calloc == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str_calloc[i] = (*f)(i, s[i]);
		i++;
	}
	return (str_calloc);
}
