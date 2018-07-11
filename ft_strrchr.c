/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:06:34 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 15:06:36 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;
	char *aux;

	ptr = (char *)str;
	aux = (char *)str;
	while (*ptr)
		ptr++;
	while (ptr != aux)
	{
		if (*ptr-- == c)
			return (++ptr);
	}
	if (*ptr == c)
		return (ptr);
	return (0);
}
