/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:07:39 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 15:07:40 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (s != 0)
	{
		ptr = (char*)malloc(sizeof(char) * (len + 1));
		if (ptr)
		{
			len += start;
			while (s[start] && start != len)
			{
				ptr[i] = s[start];
				i++;
				start++;
			}
			ptr[i] = 0;
			return (ptr);
		}
	}
	return (0);
}
