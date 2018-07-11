/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:02:32 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 15:02:34 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;

	if (s1 && s2)
	{
		ptr = (char *)malloc(sizeof(char) *
				(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1));
		if (ptr)
		{
			ft_strcpy(ptr, s1);
			ft_strcat(ptr, s2);
			ptr[ft_strlen((char*)s1) + ft_strlen((char*)s2)] = '\0';
			return (ptr);
		}
	}
	return (0);
}
