/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:05:56 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/26 00:00:35 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Simple implementation of nanf (float version)
float ft_nanf(const char *tagp)
{
    union {
        uint32_t i;
        float f;
    } u;

    // 1. Start with the Quiet NaN bit pattern for float
    // Exponent: all 1s (0x7F800000)
    // Quiet bit: The first bit of the mantissa is usually 1 (0x00400000)
    u.i = 0x7FC00000;

    // 2. Add the tag (payload) into the lower bits of the mantissa
    if (tagp && *tagp)
    {
        uint32_t payload = (uint32_t)ft_atoi(tagp);
        // Mask it to ensure it fits in the 22 bits left in the mantissa
        u.i |= (payload & 0x3FFFFF);
    }
    
    return u.f;
}

double	ft_pow(double base, int exp)
{
	if (exp == 0)
		return (1.0);
	if (exp < 0)
		return (1.0 / ft_pow(base, -exp));
	return (base * ft_pow(base, exp - 1));
}