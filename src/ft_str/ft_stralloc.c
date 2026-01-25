/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 23:48:11 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/08 23:51:31 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_stralloc(size_t size)
{
	char	*str;

	str = (char *)malloc(size);
	if (!str)
		return (NULL);
	return (str);
}

void	ft_stralloc_free(char *str)
{
	if (!str)
		return; 
	free(str);
}