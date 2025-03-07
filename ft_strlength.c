/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:57:40 by yrhandou          #+#    #+#             */
/*   Updated: 2025/03/07 15:25:19 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int *ft_super_strlen(char **array)
{
	int i;
	int j;
	int *result;

	j = 0;
	i = 0;
	while (array[i])
		i++;
	result = malloc(sizeof(int) * i);
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			result[i] = ft_strlen(array[i]);
			j++;
		}
		i++;
	}
	return (result);
}
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && dstsize - 1 > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t ld;
	size_t ls;
	size_t j;

	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	j = 0;
	if (dstsize == 0)
		return (ls);
	if (dstsize <= ld)
		return (dstsize + ls);
	while (src[j] != '\0' && j + ld < dstsize - 1)
	{
		dst[ld + j] = src[j];
		j++;
	}
	dst[ld + j] = '\0';
	return (ld + ls);
}
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	if (n == i)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
