/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:00:53 by yrhandou          #+#    #+#             */
/*   Updated: 2025/04/16 20:48:26 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (NULL);
}

char *ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (NULL);
}
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)(&haystack[i]));
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			k = i;
			while (needle[j] && k < len && haystack[k] == needle[j])
			{
				k++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}

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
	str = ft_calloc(len + 1,sizeof(char));
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
	str = ft_calloc(total_size + 1, sizeof(char));
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
	str = ft_calloc(len + 1,sizeof(char));
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
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	char *str;
	unsigned int len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = ft_calloc(len + 1,sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
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
	str = (char **)ft_calloc((word_counter(s, c) + 1), sizeof(char *));
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
int	ft_str_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	ft_is_int_array(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putendl_fd(RED "Failure: Empty Array", 2), FAIL);
	while (s[i])
	{
		if (!ft_is_int(s[i]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	ft_is_duplicated(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (ft_putendl_fd(RED "Failure: Empty Array", 2), FAIL);
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (SUCCESS);
			j++;
		}
		i++;
	}
	return (FAIL);
}

int	ft_is_sorted(char **str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (ft_atoi_modified(str[i]) > ft_atoi_modified(str[i + 1]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}
