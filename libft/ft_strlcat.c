/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:31:14 by aeberius          #+#    #+#             */
/*   Updated: 2024/04/18 12:08:09 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len_concat;
	size_t	dst_len_original;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len_concat = ft_strlen(dst);
	dst_len_original = ft_strlen(dst);
	i = 0;
	if (size == 0)
		return (src_len);
	if (size < dst_len_original)
		return (src_len + size);
	while (src[i] && dst_len_concat < size - 1)
	{
		dst[dst_len_concat] = src[i];
		dst_len_concat++;
		i++;
	}
	dst[dst_len_concat] = '\0';
	return (dst_len_original + src_len);
}
