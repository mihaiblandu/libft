/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:41:51 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/25 23:38:30 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#ifndef ARRAY_LIST_H
# define ARRAY_LIST_H

typedef struct s_array_list
{
	void	**data;
	size_t	size;
	size_t	capacity;
}	t_array_list;

/* Gestiune */
t_array_list	*array_list_new(size_t initial_capacity);
t_array_list	*array_list_create(void);
void			array_list_free(t_array_list *list);
void			array_list_clear(t_array_list *list);

/* Modificare */
int				array_list_add(t_array_list *list, void *element);
int				array_list_insert(t_array_list *list, void *element, size_t index);
void			array_list_remove(t_array_list *list, size_t index);
void			*array_list_pop(t_array_list *list);

/* Interogare & Utilitare */
void			*array_list_get(t_array_list *list, size_t index);
size_t			array_list_size(t_array_list *list);
void			array_list_reverse(t_array_list *list);
void			array_list_foreach(t_array_list *list, void (*f)(void *));
t_array_list	*array_list_slice(t_array_list *list, size_t start, size_t len);

#endif