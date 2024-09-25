/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:22:26 by aeberius          #+#    #+#             */
/*   Updated: 2024/09/25 12:53:31 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
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

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;

	i = 0;
	s1_size = ft_strlen_gnl(s1);
	s2_size = ft_strlen_gnl(s2);
	result = ft_calloc_gnl(s1_size + s2_size + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < s1_size)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_size)
		result[s1_size++] = s2[i++];
	result[s1_size] = '\0';
	free(s1);
	free(s2);
	return (result);
}
