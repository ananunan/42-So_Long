/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:23:51 by aeberius          #+#    #+#             */
/*   Updated: 2024/04/30 16:16:06 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_mlc;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str_mlc = ft_calloc(sizeof(char), len + 1);
	if (str_mlc == NULL)
		return (NULL);
	while (i < len)
	{
		str_mlc[i] = s[start + i];
		i++;
	}
	str_mlc[i] = '\0';
	return (str_mlc);
}
