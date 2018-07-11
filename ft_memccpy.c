/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:51:31 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 14:51:35 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, unsigned int n)
{
	unsigned int		i;
	unsigned char		*ptr_dest;
	const unsigned char *ptr_src;
	unsigned char		s;

	s = (unsigned char)c;
	i = 0;
	ptr_dest = (unsigned char*)dst;
	ptr_src = src;
	if (n)
	{
		while (i < n)
		{
			if ((*ptr_dest++ = ptr_src[i]) == s)
				return (ptr_dest);
			i++;
		}
	}
	return (0);
}
