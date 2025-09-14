/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:19:05 by mihai.bland       #+#    #+#             */
/*   Updated: 2025/09/14 22:12:27 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/libft.h"

void	ft_putstr(char *str)
{
	int		i;

	i = ft_strlen(str);
	write(1, str, i);
}
