/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihai.blandu <mihai.blandu@ctif.gov.md>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:48:19 by mihai.bland       #+#    #+#             */
/*   Updated: 2024/02/27 00:52:54 by mihai.bland      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_dst < ptr_src)
	{
		while (len--)
			*ptr_dst++ = *ptr_src++;
	}
	else
	{
		ptr_dst += len;
		ptr_src += len;
		while (len--)
			*--ptr_dst = *--ptr_src;
	}
	return (dst);
}