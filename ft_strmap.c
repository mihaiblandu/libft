/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:03:24 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 15:03:27 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = 0;
	if (s && f)
	{
		ptr = (char*)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
		if (ptr)
		{
			while (*s)
			{
				ptr[i] = f(*s);
				i++;
				s++;
			}
			ptr[i] = 0;
			return (ptr);
		}
	}
	return (0);
}
