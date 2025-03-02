/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihai.blandu <mihai.blandu@ctif.gov.md>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:25:08 by mihai.bland       #+#    #+#             */
/*   Updated: 2024/02/29 20:25:08 by mihai.bland      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"

void	*ft_arraylist_new(size_t size)
{
	void	*array;

	array = malloc(size);
	if (!array)
		return (NULL);
	ft_bzero(array, size);
	return (array);
}