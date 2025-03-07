/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:59:28 by yrhandou          #+#    #+#             */
/*   Updated: 2025/03/07 14:59:51 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*leftovers(char *s)
{
	char	*left;
	size_t	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (!ft_strchr(s, '\n'))
		return (NULL);
	left = ft_substr(s, i, ft_strlen(ft_strchr(s, '\n')));
	return (left);
}

static char	*get_one_line(const char *str)
{
	char	*one_line;
	size_t	i;

	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	one_line = ft_substr(str, 0, i);
	return (one_line);
}

static char	*read_buffer(int fd, char *bag)
{
	ssize_t	byte_count;
	char	*temp;
	char	*buffer;

	temp = 0;
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (free(bag), bag = NULL, NULL);
	while (ft_strchr(bag, '\n') == NULL)
	{
		byte_count = read(fd, buffer, BUFFER_SIZE);
		if (byte_count < 0)
			return (free(buffer), free(bag), NULL);
		if (byte_count == 0)
			break ;
		buffer[byte_count] = '\0';
		temp = bag;
		bag = ft_strjoin(bag, buffer);
		free(temp);
	}
	return (free(buffer), bag);
}
int ft_getchar(void)
{
	unsigned char c;
	int bytes_read;

	bytes_read = read(0, &c, 1);
	if (bytes_read <= 0)
		return (-1);
	return ((int)c);
}

char	*super_get_next_line(int fd)
{
	static char	*bag[OPEN_MAX];
	char		*line;
	char		*temp;

	temp = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bag[fd] = read_buffer(fd, bag[fd]);
	if (!bag[fd])
		return (free(bag[fd]), bag[fd] = NULL, NULL);
	line = get_one_line(bag[fd]);
	if (!line)
		return (free(bag[fd]), bag[fd] = NULL, NULL);
	temp = bag[fd];
	bag[fd] = leftovers(bag[fd]);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*bag;
	char		*line;
	char		*temp;

	temp = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(bag), NULL);
	bag = read_buffer(fd, bag);
	if (!bag)
		return (free(bag), bag = NULL, NULL);
	line = get_one_line(bag);
	if (!line)
		return (free(bag), bag = NULL, NULL);
	temp = bag;
	bag = leftovers(bag);
	free(temp);
	return (line);
}
