/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:58:16 by yrhandou          #+#    #+#             */
/*   Updated: 2025/04/06 14:11:07 by yrhandou         ###   ########.fr       */
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
void ft_lstadd_back(t_list **lst, t_list *new){
	
}
void ft_lstdelone(t_list *lst, void (*del)(void *)){
	
}
void ft_lstclear(t_list **lst, void (*del)(void *)){
	
}
void ft_lstiter(t_list *lst, void (*f)(void *)){
	
}
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)){
	
}
