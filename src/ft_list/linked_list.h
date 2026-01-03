/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:15:26 by mihaiblandu       #+#    #+#             */
/*   Updated: 2025/12/31 16:15:26 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H


typedef struct s_list_node
{
    void					*content;
    struct s_list_node		*next;
    struct s_list_node		*prev;

}	t_list_node;


// create a new doubly linked list node

t_list_node	*linked_list_node_new(void *content);
// free a doubly linked list node
void		linked_list_node_free(t_list_node *node);
// free a doubly linked list starting from the given node
void		linked_list_free(t_list_node *head);

#endif