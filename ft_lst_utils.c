/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:58:16 by yrhandou          #+#    #+#             */
/*   Updated: 2025/04/13 12:40:56 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if(!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return node;
}
void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return;
	new->next = *lst;
	(*lst) = new;
}

int ft_lstsize(t_list *lst)
{
	t_list *tmp;
	int i;

	tmp = lst;
	i = 0;
	while(tmp)
	{
		i++;
		tmp= tmp->next;
	}
	return (i);
}

t_list *ft_lstlast(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if(tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
// void ft_lstadd_back(t_list **lst, t_list *new){

// }
void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return;
	if (del && lst->content)
		del(lst->content);
	free(lst);
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	
	if (!lst || !*lst)
		return;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (!new)
		return;
	if (!*lst)
	{
		*lst = new;
		return;
	}
	last = ft_lstlast(*lst);
	if (last)
		last->next = new;
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *new_node;
	void *new_content;

	if (!f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (del && new_content)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// t_list *create_node(int data)
// {
// 	t_list *new_node = (t_list *)malloc(sizeof(t_list));
// 	if (!new_node)
// 		return NULL;
// 	new_node->content = data;
// 	new_node->next = NULL;
// 	return new_node;
// }

// void link_node(t_list *head, int data)
// {
// 	t_list *new_node = create_node(data);
// 	if (!new_node)
// 		return;
// 	head->next = new_node;
// }

// void ft_push_node(t_list **head, int data)
// {
// 	(**head)->content = data;
// 	// ? t_list **tmp = head;
// 	// ! t_list *new_node = create_node(data);
// 	// ^ if (!new_node)
// 	// *	return;
// 	// new_node->next = *head;
// 	// *head = new_node;
// }
// void print_stacks_side_by_side(t_list *stack1, t_list *stack2)
// {
// 	while ((stack1 != NULL) || (stack2 != NULL))
// 	{
// 		if (stack1 != NULL)
// 		{
// 			ft_printf(BHBLU "|{%d}|\t", stack1->content);
// 			stack1 = stack1->next;
// 		}
// 		else
// 			ft_putstr_fd(RESET "|---|   ", 1);
// 		if (stack2 != NULL)
// 		{
// 			ft_printf(BHGRN "|{%d}|\t", stack2->content);
// 			stack2 = stack2->next;
// 		}
// 		else
// 			ft_putstr_fd("   ", 1);
// 		ft_putstr_fd("\n", 1);
// 	}
// 	ft_putstr_fd(RESET "-------------", 1);
// 	ft_putstr_fd(BLU "\nStack A ", 1);
// 	ft_putstr_fd(GRN "Stack B\n", 1);
// 	ft_putstr_fd(RESET "", 1);
// }

// void print_stack(t_list *stack)
// {
// 	ft_printf(BLU "|     |\n");
// 	while (stack)
// 	{
// 		ft_printf(GRN "| {%d} |\n", stack->content);
// 		stack = stack->next;
// 	}
// 	ft_printf(BLU "-------\n");
// 	ft_printf(BLK "Stack A\n");
// }
