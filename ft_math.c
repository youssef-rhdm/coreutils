/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:40:04 by yrhandou          #+#    #+#             */
/*   Updated: 2025/04/06 11:44:25 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int *ft_factors_count(int num)
{
	int i;
	int counter;
	int *factors;

	i = 1;
	counter = 0;
	while (i <= num / 2)
	{
		if (num % i == 0)
			counter++;
		i++;
	}
	factors = ft_calloc(counter + 1,sizeof(int));
	if (!factors)
		return (NULL);
	counter = 0;
	factors[counter++] = num;
	while (i >= 1)
	{
		if (num % i == 0)
			factors[counter++] = i;
		i--;
	}
	return (factors);
}

int ft_abs(int num)
{
	if (num < 0)
		return (num * (-1));
	return (num);
}
double	ft_pow(double num,double power)
{
	if (!num)
		return (0);
	if (!power)
		return (1);
	if(power < 0)
	{
		num = (float)(1 / num);
		power = ft_abs(power);
	}
	while (power>1)
	{
		num *=num;
		power--;
	}
	return (num);
}
