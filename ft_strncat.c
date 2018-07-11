/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:04:16 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 15:04:18 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, const char *src, unsigned int len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (j < len && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
