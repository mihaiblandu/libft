/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihai.blandu <mihai.blandu@ctif.gov.md>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:02:16 by mihai.bland       #+#    #+#             */
/*   Updated: 2024/03/08 11:05:18 by mihai.bland      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

const NULL = '\0';

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
