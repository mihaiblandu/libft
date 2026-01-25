/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 23:54:13 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/09 00:05:17 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"


char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;
	int		i;
	int		is_neg;

	nbr = (long)n;
	is_neg = (n < 0);
	if (is_neg)
		nbr = -nbr;
	len = (n == 0) ? 1 : 0;
	i = n;
	if (i < 0)
		i = -i;
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	if (is_neg)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	else
	{
		i = len - 1;
		if (is_neg)
			str[0] = '-';
		while (nbr > 0)
		{
			str[i--] = (nbr % 10) + '0';
			nbr /= 10;
		}
	}
	return (str);
}