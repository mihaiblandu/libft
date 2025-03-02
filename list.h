/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihai.blandu <mihai.blandu@ctif.gov.md>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:12:34 by mihai.bland       #+#    #+#             */
/*   Updated: 2024/02/28 22:12:59 by mihai.bland      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_arraylist
{
	void	*array;
	size_t	size;
}				t_arraylist;

#endif