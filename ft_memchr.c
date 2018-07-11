/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:51:50 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 14:51:53 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ptr;
	unsigned char	key;

	key = (unsigned char)c;
	ptr = (unsigned char*)s;
	i = 0;
	while (i++ < n)
		if (*ptr++ == key)
			return (--ptr);
	return (0);
}
