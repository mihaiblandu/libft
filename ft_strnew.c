/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:05:25 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 15:05:27 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr)
	{
		ft_bzero(ptr, size + 1);
		return (ptr);
	}
	return (0);
}
