/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:00:00 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/09 00:00:00 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_slice(const void *array, size_t start, size_t len, size_t elem_size)
{
	void	*slice;
	size_t	i;

	if (!array || elem_size == 0)
		return (NULL);
	slice = malloc(len * elem_size);
	if (!slice)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ft_memcpy((char *)slice + (i * elem_size),
			(const char *)array + ((start + i) * elem_size), elem_size);
		i++;
	}
	return (slice);
}
