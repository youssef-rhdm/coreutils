/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super_strlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:42:18 by yrhandou          #+#    #+#             */
/*   Updated: 2025/02/16 10:44:31 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_super_strlen(char **array)
{
	int	i;
	int	j;
	int	*result;

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
