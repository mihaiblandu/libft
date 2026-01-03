/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:25:08 by mihai.bland       #+#    #+#             */
/*   Updated: 2026/01/02 23:38:59 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_arraylist_new(size_t size)
{
	void *array;

	array = malloc(size);
	if (!array)
		return (NULL);
	ft_bzero(array, size);
	return (array);
}