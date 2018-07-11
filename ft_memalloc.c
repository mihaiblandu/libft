/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:51:13 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 14:51:14 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(sizeof(void) * size);
	if (ptr == 0)
		return (0);
	return (ft_bzero(ptr, size));
}
