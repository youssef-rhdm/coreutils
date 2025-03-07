/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:00:53 by yrhandou          #+#    #+#             */
/*   Updated: 2025/03/07 15:37:07 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
int ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
char *ft_strdup(const char *s1)
{
	size_t i;
	size_t len;
	char *str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *head;
	char *str;
	size_t total_size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(total_size + 1);
	if (str == NULL)
		return (NULL);
	head = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (head);
}
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t length;
	char *str;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (length <= start)
		len = 0;
	else if (len > length - start)
		len = length - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}
char *ft_strtrim(char const *s1, char const *set)
{
	size_t x;
	size_t len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	x = 0;
	while (s1[x] && ft_strchr(set, s1[x]))
		x++;
	while (x < len && ft_strchr(set, s1[len - 1]))
		len--;
	return (ft_substr(s1, x, len - x));
}
void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	i = 0;
	if (!s || !f)
		return;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
static int word_counter(char const *str, char c)
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			counter++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (counter);
}

static int count_sub(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static char **free_arr(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (NULL);
}

char **ft_split(char const *s, char c)
{
	int i;
	int x;
	char **str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	x = -1;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			str[++x] = ft_substr(s, i, count_sub(&s[i], c));
			if (!str[x])
				return (free_arr(str));
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (str[++x] = NULL, str);
}
void ft_bzero(void *s, size_t n)
{
	size_t i;
	unsigned char *str;

	str = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
