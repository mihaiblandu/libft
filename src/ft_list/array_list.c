/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:40:37 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/03 00:09:08 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array_list.h"

t_array_list	*array_list_new(size_t initial_capacity)
{
	t_array_list	*list;

	list = malloc(sizeof(t_array_list));
	if (!list)
		return (NULL);
	list->data = malloc(sizeof(void *) * initial_capacity);
	if (!list->data)
	{
		free(list);
		return (NULL);
	}
	list->size = 0;
	list->capacity = initial_capacity;
	return (list);
}

t_array_list	*array_list_create(void)
{
	return (array_list_new(4));
}

void	array_list_free(t_array_list *list)
{
	if (!list)
		return ;
	free(list->data);
	free(list);
}
void	array_list_clear(t_array_list *list)
{
	if (!list)
		return ;
	list->size = 0;
}

// Modificare
int	array_list_add(t_array_list *list, void *element)
{
	void	**new_data;
	size_t	new_capacity;
	size_t	i;

	if (list->size >= list->capacity)
	{
		new_capacity = list->capacity * 2;
		new_data = malloc(sizeof(void *) * new_capacity);
		if (!new_data)
			return (0);
		i = 0;
		while (i < list->size)
		{
			new_data[i] = list->data[i];
			i++;
		}
		free(list->data);
		list->data = new_data;
		list->capacity = new_capacity;
	}
	list->data[list->size] = element;
	list->size++;
	return (1);
}

int	array_list_insert(t_array_list *list, void *element, size_t index)
{
	size_t	i;

	if (index > list->size)
		return (0);
	if (list->size >= list->capacity)
	{
		if (!array_list_add(list, NULL))
			return (0);
        list->size--; // Adjust size back since add increments it
	}
	i = list->size;
	while (i > index)
	{
		list->data[i] = list->data[i - 1];
		i--;
	}
	list->data[index] = element;
	list->size++;
	return (1);
}

void	array_list_remove(t_array_list *list, size_t index)
{
	size_t	i;

	if (index >= list->size)
		return ;
	i = index;
	while (i < list->size - 1)
	{
		list->data[i] = list->data[i + 1];
		i++;
	}
	list->size--;
}

void	*array_list_pop(t_array_list *list)
{
	void	*element;

	if (list->size == 0)
		return (NULL);
	element = list->data[list->size - 1];
	list->size--;
	return (element);
}

// Interogare & Utilitare
void	*array_list_get(t_array_list *list, size_t index)
{
	if (index >= list->size)
		return (NULL);
	return (list->data[index]);
}

size_t	array_list_size(t_array_list *list)
{
	return (list->size);
}

void	array_list_reverse(t_array_list *list)
{
	size_t	i;
	void	*temp;

	i = 0;
	while (i < list->size / 2)
	{
		temp = list->data[i];
		list->data[i] = list->data[list->size - 1 - i];
		list->data[list->size - 1 - i] = temp;
		i++;
	}
}

void	array_list_foreach(t_array_list *list, void (*f)(void *))
{
	size_t	i;

	i = 0;
	while (i < list->size)
	{
		f(list->data[i]);
		i++;
	}
}
