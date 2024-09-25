/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:17:40 by aeberius          #+#    #+#             */
/*   Updated: 2024/04/26 20:19:20 by aeberius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digit(int c);
char	*malloc_fill(int size, char *malloc_str, int n, int neg_flag);

char	*ft_itoa(int n)
{
	int		size;
	char	*malloc_str;
	int		neg_flag;

	size = 0;
	neg_flag = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		size = ft_count_digit(n) + 1;
		neg_flag = 1;
	}
	else
		size = ft_count_digit(n);
	malloc_str = ft_calloc (sizeof(char), size + 1);
	if (malloc_str == NULL)
		return (NULL);
	malloc_str = malloc_fill(size, malloc_str, n, neg_flag);
	return (malloc_str);
}

char	*malloc_fill(int size, char *malloc_str, int n, int neg_flag)
{
	while (size > 0)
	{
		size --;
		malloc_str[size] = n % 10 + '0';
		n = n / 10;
	}
	if (size == 0 && neg_flag == 1)
		malloc_str[0] = '-';
	return (malloc_str);
}

int	ft_count_digit(int c)
{
	int	count;

	count = 0;
	if (c >= 10)
		count = ft_count_digit(c / 10);
	count ++;
	return (count);
}
