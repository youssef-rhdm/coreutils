/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:39:59 by yrhandou          #+#    #+#             */
/*   Updated: 2025/03/07 15:41:33 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
	unsigned char *ptr;
	size_t i;
	size_t alloc_size;

	alloc_size = size * count;
	if (count && size && alloc_size / count != size)
		return (NULL);
	i = 0;
	ptr = malloc(alloc_size);
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

static char sign_check(const char *str, int *sign)
{
	int i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int ft_atoi(const char *str)
{
	int i;
	int sign;
	long temp;
	long result;

	sign = 1;
	i = 0;
	result = 0;
	i = sign_check(str, &sign);
	while (ft_isdigit(str[i]))
	{
		temp = result;
		result = result * 10 + (str[i] - '0');
		if (result / 10 != temp)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	return ((int)(result * sign));
}

static int count_num(int num)
{
	int count;

	count = 1;
	while (num / 10 != 0)
	{
		count++;
		num = num / 10;
	}
	return (count);
}

static char *itoa_ft(int count, int n)
{
	char *str;

	str = (char *)malloc(count + 2);
	if (!str)
		return (NULL);
	str[count + 1] = '\0';
	str[0] = '-';
	while (count)
	{
		str[count--] = (n % 10) * (-1) + '0';
		n = n / 10;
	}
	return (str);
}

char *ft_itoa(int n)
{
	int count;
	char *str;

	count = count_num(n);
	if (n < 0)
		return (itoa_ft(count, n));
	str = (char *)malloc(count + 1);
	if (!str)
		return (NULL);
	else
		str[count] = '\0';
	while (count--)
	{
		str[count] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
