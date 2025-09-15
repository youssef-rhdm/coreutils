/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:54 by yrhandou          #+#    #+#             */
/*   Updated: 2025/03/07 14:38:46 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	const unsigned char *str;

	if (!s || n == 0)
		return (NULL);
	i = 0;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	const unsigned char *str1;
	const unsigned char *str2;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	if (n == 0)
		return (0);
	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
void *ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;
	unsigned char *dest;
	const unsigned char *sorc;

	if (!dst && !src)
		return (NULL);
	if (n == 0)
		return (dst);
	dest = (unsigned char *)dst;
	sorc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dst);
}
void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	unsigned char *dest;
	const unsigned char *srce;

	dest = (unsigned char *)dst;
	srce = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest > srce)
	{
		while (len--)
			dest[len] = srce[len];
	}
	else if (dest < srce)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = srce[i];
			i++;
		}
	}
	return (dst);
}
void *ft_memset(void *b, int c, size_t len)
{
	size_t i;
	unsigned char *str;

	if (!b)
		return (NULL);
	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
