/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:08:57 by yrhandou          #+#    #+#             */
/*   Updated: 2024/12/07 10:08:57 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}
int ft_putstr(char *str)
{
	int i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
int ft_putnbr(int n)
{
	int count;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	else if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
		count += ft_putnbr(n);
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}

int ft_puthex(unsigned long nbr, char flag)
{
	int count;
	char *hex_list;

	count = 0;
	if (flag == 'X')
		hex_list = "0123456789ABCDEF";
	else if (flag == 'x')
		hex_list = "0123456789abcdef";
	if (nbr > 15)
	{
		count += ft_puthex(nbr / 16, flag);
		count += ft_puthex(nbr % 16, flag);
	}
	else
		count += ft_putchar(hex_list[nbr]);
	return (count);
}
int ft_putptr(void *ptr, char flag)
{
	int count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr, flag);
	return (count);
}

int ft_putuint(unsigned int n)
{
	int count;

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
static int check_format(va_list va, char str)
{
	int counter;

	counter = 0;
	if (str == 's')
		counter += ft_putstr(va_arg(va, char *));
	else if (str == 'c')
		counter += ft_putchar(va_arg(va, int));
	else if (str == 'p')
		counter += ft_putptr(va_arg(va, void *), 'x');
	else if (str == 'd' || str == 'i')
		counter += ft_putnbr(va_arg(va, int));
	else if (str == 'u')
		counter += ft_putuint(va_arg(va, unsigned int));
	else if (str == 'x' || str == 'X')
		counter += ft_puthex(va_arg(va, unsigned int), str);
	else
		counter += ft_putchar(str);
	return (counter);
}

int ft_printf(const char *str, ...)
{
	int counter;
	int i;
	va_list va;

	i = 0;
	counter = 0;
	va_start(va, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			counter += ft_putchar(str[i]);
		if (str[i] == '%' && str[i + 1] != '\0')
			counter += check_format(va, str[++i]);
		i++;
	}
	va_end(va);
	return (counter);
}
