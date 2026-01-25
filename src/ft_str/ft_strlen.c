/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:00:00 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/09 05:58:37 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t ft_strlen(const char *s)
{
    const char *ptr = s;
    unsigned long long chunk;
    
    // Process byte-by-byte until aligned
    while ((unsigned long)ptr & 7)
    {
        if (*ptr == '\0')
            return (ptr - s);
        ptr++;
    }
    
    // Process 64-bit chunks
    while (1)
    {
        chunk = *(unsigned long long *)ptr;
        
        // Check for null byte (SWAR technique)
        if (((chunk - 0x0101010101010101ULL) & ~chunk & 0x8080808080808080ULL))
            break;
        
        ptr += 8;
    }
    
    // Find exact null byte position
    while (*ptr)
        ptr++;
    
    return (ptr - s);
}