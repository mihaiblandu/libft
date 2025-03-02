/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihai.blandu <mihai.blandu@ctif.gov.md>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:25:47 by mihai.bland       #+#    #+#             */
/*   Updated: 2024/02/26 23:37:55 by mihai.bland      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, void const *src, size_t n)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (!dest && !src)
		return (dest);
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (dest_ptr);
}
