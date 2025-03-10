/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:40:04 by yrhandou          #+#    #+#             */
/*   Updated: 2025/03/09 17:50:17 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int *ft_factors(int num)
{
	int i;
	int counter;

	i = 2;
	counter = 0;
	while (i < num)
	{
		if (num % i)
		{
			counter++;
		}
		i++;
	}
}

int ft_lcm(int a, int b)
{
}
