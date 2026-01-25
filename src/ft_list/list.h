/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:12:34 by mihai.bland       #+#    #+#             */
/*   Updated: 2026/01/04 23:27:36 by mihaiblandu      ###   ########.fr       */
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

}				t_list;

typedef struct s_arraylist
{
	void	*array;
	size_t	size;
}				t_arraylist;

typedef struct s_slice
{
	void	*data;
	size_t	start;
	size_t	len;
	size_t	elem_size;
	int		owned;
}				t_slice;

t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *list);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstadd_end(t_list **list, void *content);

#endif