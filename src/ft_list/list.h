/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:12:34 by mihai.bland       #+#    #+#             */
/*   Updated: 2026/01/03 17:15:20 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*head;
	struct s_list	*tail;
	size_t			size;
}				t_list;

typedef struct s_arraylist
{
	void	*array;
	size_t	size;
}				t_arraylist;

#endif