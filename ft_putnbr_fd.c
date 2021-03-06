/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:56:30 by mblandu           #+#    #+#             */
/*   Updated: 2017/11/28 14:56:46 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_check(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (1);
	}
	if (n == 2147483647)
	{
		ft_putstr_fd("2147483647", fd);
		return (1);
	}
	return (0);
}

void			ft_putnbr_fd(int n, int fd)
{
	int var;
	int size;

	if (ft_check(n, fd))
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	var = n;
	size = 1;
	while ((n / 10) > 0)
	{
		n = n / 10;
		size = size * 10;
	}
	while (size != 0)
	{
		ft_putchar_fd((char)((var / size) + 48), fd);
		var = var % size;
		size = size / 10;
	}
}
