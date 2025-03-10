/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:16:40 by yrhandou          #+#    #+#             */
/*   Updated: 2025/03/03 09:01:41 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *str, char delimiter)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == delimiter)
			i++;
		else if (str[i] != delimiter)
		{
			count++;
			while (str[i] && str[i] != delimiter)
				i++;
		}
	}
	return (count);
}
