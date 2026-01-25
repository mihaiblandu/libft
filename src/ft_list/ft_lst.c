/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:02:16 by mihai.bland       #+#    #+#             */
/*   Updated: 2026/01/25 23:45:56 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		ft_lstsize(t_list *list)
{
	int		size;
	t_list	*l;

	l = list;
	size = 0;
	while (l) {
		size++;
		l = l->next;
	}
	return (size);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list *ft_lst_add(t_list *list, void *content)
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->prev = list;
	new->next = NULL;
	
	if (list)
		list->next = new;
	
	return (new);
}

void ft_node_remove(t_list **node)
{
	if (!node || !*node)
		return;
	
	if ((*node)->prev)
		(*node)->prev->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	
	free(*node);
	*node = NULL;  // Protection against double-free
}

// pop - removes and frees the last node
void ft_lst_pop(t_list **list)
{
	t_list *current;
	
	if (!list || !*list)
		return;
	
	// Find the last node
	current = *list;
	while (current->next)
		current = current->next;
	
	// Update links before removing
	if (current->prev == NULL)
		*list = NULL;
	else
		current->prev->next = NULL;
	
	// Free with protection
	ft_node_remove(&current);
}

// add to start
void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return;
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
	}
	else
		new->next = NULL;
	new->prev = NULL;
	*lst = new;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tail;

	if (!lst || !new)
		return;
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		new->prev = NULL;
		return;
	}
	tail = *lst;
	while (tail->next)
		tail = tail->next;
	tail->next = new;
	new->prev = tail;
	new->next = NULL;
}
t_list *ft_lst_add_end(t_list **list, void *content)
{
	t_list	*tail;
	t_list	*new;

	if(!list)
		return (ft_lstnew(content));

	tail = *list;

	while (tail->next) {
		tail = tail->next;
	}

	new = ft_lstnew(content);
	new->prev = tail;
	new->next = NULL;
	tail->next = new;
	return (new);
}
