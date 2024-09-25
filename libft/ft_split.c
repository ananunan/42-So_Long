/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:32:11 by aeberius          #+#    #+#             */
/*   Updated: 2024/05/01 13:00:43 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count_words ++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count_words);
}

int	ft_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count_word;
	int		word_index;
	int		char_index;

	word_index = 0;
	char_index = 0;
	if (s == NULL)
		return (NULL);
	count_word = ft_count_words(s, c);
	result = ft_calloc(count_word + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (word_index < count_word)
	{
		while (s[char_index] && s[char_index] == c)
			char_index++;
		result[word_index] = ft_substr(s + char_index, 0,
				ft_word_len(s + char_index, c));
		char_index = char_index + ft_word_len(s + char_index, c);
		word_index++;
	}
	return (result);
}
