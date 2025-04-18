/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:36:22 by yrhandou          #+#    #+#             */
/*   Updated: 2025/04/17 23:38:29 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
int ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
int ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
int ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
int ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
int ft_is_int(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (ft_putendl_fd(RED "Failure: Empty Array", 2), FAIL);
	if ((str[0] == '-' || str[0] == '+') && str[i + 1] != '\0')
		i++;
	else if ((str[0] == '-' || str[0] == '+') && str[i + 1] == '\0')
		return (FAIL);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FAIL);
		i++;
	}
	if ((ft_atoi_modified(str) > INT_MAX || ft_atoi_modified(str) < INT_MIN))
		return (FAIL);
	return (SUCCESS);
}
int ft_is_uint(char *str)
{
	if (!ft_is_int(str) || str[0] == '-')
		return (0);
	if (ft_atoi(str) < 0 || (unsigned int)ft_atoi(str) > __UINT32_MAX__)
		return 0;
	return 0;
}
