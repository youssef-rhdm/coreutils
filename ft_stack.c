/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:59:25 by yrhandou          #+#    #+#             */
/*   Updated: 2025/03/02 12:24:53 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"
#include "utils/libft.h"

void print_stacks_side_by_side(t_stack *stack1, t_stack *stack2)
{
	while (stack1 != NULL || stack2 != NULL)
	{
		if (stack1 != NULL)
		{
			ft_printf(BHBLU "|{%d}|\t", stack1->data);
			stack1 = stack1->next;
		}
		else
			ft_putstr_fd(RESET "|---|   ", 1);
		if (stack2 != NULL)
		{
			ft_printf(BHGRN "|{%d}|\t", stack2->data);
			stack2 = stack2->next;
		}
		else
			ft_putstr_fd("   ", 1);
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd(RESET "-------------", 1);
	ft_putstr_fd(BLU "\nStack A ", 1);
	ft_putstr_fd(GRN "Stack B\n", 1);
	ft_putstr_fd(RESET "", 1);
}

void print_stack(t_stack *stack)
{
	ft_printf(BLU "|     |\n");
	while (stack)
	{
		ft_printf(GRN "| {%d} |\n", stack->data);
		stack = stack->next;
	}
	ft_printf(BLU "-------\n");
	ft_printf(BLK "Stack A\n");
}
t_stack *create_node(int data)
{
	t_stack *new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return NULL;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
void push_node(t_stack **head, int data)
{
	t_stack *new_node;

	new_node = create_node(data);
	if (!new_node)
		return;
	if (!(*head))
	{
		*head = new_node;
		return;
	}
	new_node->next = *head;
	*head = new_node;
}
