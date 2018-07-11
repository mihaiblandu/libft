/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:53:02 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 14:53:03 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned int		i;
	unsigned char		*ptr_dest;
	const unsigned char *ptr_src;

	ptr_dest = dst;
	ptr_src = src;
	i = 0;
	if (ptr_dest > ptr_src)
		while (len--)
		{
			ptr_dest[len] = ptr_src[len];
		}
	else
	{
		while (i < len)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dst);
}
