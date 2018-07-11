/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:04:00 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 15:04:02 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (s && f)
	{
		ptr = (char*)malloc((ft_strlen((char*)s) + 1) * sizeof(char));
		if (ptr)
		{
			while (*s)
			{
				ptr[i] = f(i, *s);
				i++;
				s++;
			}
			ptr[i] = 0;
			return (ptr);
		}
	}
	return (0);
}
