/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:07:45 by yrhandou          #+#    #+#             */
/*   Updated: 2025/03/11 21:19:08 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

int *ft_factors_count(int num)
{
	int i;
	int counter;

	i = 1;
	counter = 0;
	while (i <= num / 2)
	{
		if (num % i == 0)
			counter++;
		i++;
	}
	int *factors = malloc(sizeof(int)* (counter + 1));
	if (!factors)
		return NULL;
	counter = 0;
	while (i>=1)
	{
		if (num % i == 0)
			factors[counter++] = i;
		i--;
	}
	return (factors);
}


// int *ft_factors(int num)
// {
// 	int *factors = malloc(sizeof(int) *(ft_factors_count(num)+1));
// 	if(!factors)
// 		return NULL;
// 	int counter = 0;
// 	while(counter<=i)
// 	{

// 		counter++;
// 	}
// 	return counter;
// ! fIX ME LATER}

int main(int argc, char const *argv[])
{
	// int i;
	// i = 0;
	// while (ft_factors_count(100)[i])
	// {
	// ft_putnbr(ft_factors_count(100)[i++]);
	// puts("");

	// }
	unsigned char a = 97;
	printf("%d",ft_factors_count(10)[0]);
	return 0;
}

