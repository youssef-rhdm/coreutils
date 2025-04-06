/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:07:45 by yrhandou          #+#    #+#             */
/*   Updated: 2025/04/06 14:08:15 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	t_list *l2;
	t_list *l1;
	t_list *l3;

	double x = 11.0;
	double Z = 88.0;
	l1 = ft_lstnew(&x);
	l2 = ft_lstnew(&Z);
	l3 = ft_lstnew(&Z);
	ft_lstadd_front(&l1,l2);
	ft_lstadd_front(&l2,l3);
	printf("%f\n",*(double *)ft_lstlast(l3)->content);
	return 0;
}

