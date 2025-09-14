/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:30:00 by mihaiblandu       #+#    #+#             */
/*   Updated: 2025/09/14 21:29:34 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_dynamic_list
{
	void	**data;
	size_t	size;
	size_t	capacity;
	size_t	element_size;
}	DynamicList;

DynamicList	*list_create(size_t element_size);
int			list_add(DynamicList *list, const void *element);
void		*list_get(DynamicList *list, size_t index);
int			list_remove(DynamicList *list, size_t index);
size_t		list_size(DynamicList *list);
void		list_free(DynamicList *list);

#endif