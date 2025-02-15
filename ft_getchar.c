/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:56:49 by yrhandou          #+#    #+#             */
/*   Updated: 2025/02/15 15:23:51 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getchar(void)
{
	unsigned char	c;
	int				bytes_read;

	bytes_read = read(0, &c, 1);
	if (bytes_read <= 0)
		return (-1);
	return ((int)c);
}
