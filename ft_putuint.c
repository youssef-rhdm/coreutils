/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:45:38 by yrhandou          #+#    #+#             */
/*   Updated: 2024/12/12 12:23:49 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putuint(n / 10);
		count += ft_putchar(n % 10 + 48);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}
