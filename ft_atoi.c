/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihai.blandu <mihai.blandu@ctif.gov.md>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:46:39 by mihai.bland       #+#    #+#             */
/*   Updated: 2024/02/28 19:57:19 by mihai.bland      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;

	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}
