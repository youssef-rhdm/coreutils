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
	t_list *list = NULL;
	t_list *node1, *node2, *node3;

	(void)argc; // Suppress unused parameter warning
	(void)argv; // Suppress unused parameter warning
	
	double x = 11.0;
	double y = 22.0;
	double z = 88.0;
	
	// Create nodes
	node1 = ft_lstnew(&x);
	node2 = ft_lstnew(&y);
	node3 = ft_lstnew(&z);
	
	if (!node1 || !node2 || !node3)
	{
		// Clean up if allocation failed
		free(node1);
		free(node2);
		free(node3);
		return 1;
	}
	
	// Build list properly: add nodes to the list
	ft_lstadd_front(&list, node1);  // list: node1
	ft_lstadd_front(&list, node2);  // list: node2 -> node1
	ft_lstadd_front(&list, node3);  // list: node3 -> node2 -> node1
	
	// Find and print the last element
	t_list *last = ft_lstlast(list);
	if (last && last->content)
		printf("%f\n", *(double *)last->content);
	
	// Free the entire list properly (no del function needed since we don't own the content)
	ft_lstclear(&list, NULL);
	
	return 0;
}

