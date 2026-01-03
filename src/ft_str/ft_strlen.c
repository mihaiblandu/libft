/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:45:58 by mihai.bland       #+#    #+#             */
/*   Updated: 2026/01/03 14:28:32 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*p;
	size_t		*w;

	p = s;
	while ((size_t)p & 7)
		if (!*p++)
			return (p - s - 1);
	w = (size_t *)p;
	while (!((*w - 0x0101010101010101UL) & (~*w & 0x8080808080808080UL)))
		w++;
	p = (char *)w;
	while (*p)
		p++;
	return (p - s);
}