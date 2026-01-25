/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 01:10:31 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/09 06:02:58 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_strncmp(const char *s1, const char *s2, int n)
{
    const unsigned char *ptr1 = (const unsigned char *)s1;
    const unsigned char *ptr2 = (const unsigned char *)s2;
    unsigned long long chunk1, chunk2;
    
    if (n == 0)
        return (0);
    
    // Process byte-by-byte until both aligned
    while (n && (((unsigned long)ptr1 & 7) || ((unsigned long)ptr2 & 7)))
    {
        if (*ptr1 != *ptr2 || *ptr1 == '\0')
            return (*ptr1 - *ptr2);
        ptr1++;
        ptr2++;
        n--;
    }
    
    // Process 64-bit chunks
    while (n >= 8)
    {
        chunk1 = *(unsigned long long *)ptr1;
        chunk2 = *(unsigned long long *)ptr2;
        
        // Check for difference or null byte
        if (chunk1 != chunk2 || 
            ((chunk1 - 0x0101010101010101ULL) & ~chunk1 & 0x8080808080808080ULL))
            break;
        
        ptr1 += 8;
        ptr2 += 8;
        n -= 8;
    }
    
    // Handle remaining bytes
    while (n--)
    {
        if (*ptr1 != *ptr2 || *ptr1 == '\0')
            return (*ptr1 - *ptr2);
        ptr1++;
        ptr2++;
    }
    
    return (0);
}

int ft_strcmp(const char *s1, const char *s2)
{
    const unsigned char *ptr1 = (const unsigned char *)s1;
    const unsigned char *ptr2 = (const unsigned char *)s2;
    unsigned long long chunk1, chunk2;
    
    // Process byte-by-byte until both aligned
    while (((unsigned long)ptr1 & 7) || ((unsigned long)ptr2 & 7))
    {
        if (*ptr1 != *ptr2 || *ptr1 == '\0')
            return (*ptr1 - *ptr2);
        ptr1++;
        ptr2++;
    }
    
    // Process 64-bit chunks
    while (1)
    {
        chunk1 = *(unsigned long long *)ptr1;
        chunk2 = *(unsigned long long *)ptr2;
        
        // Check for difference or null byte
        if (chunk1 != chunk2 || 
            ((chunk1 - 0x0101010101010101ULL) & ~chunk1 & 0x8080808080808080ULL))
            break;
        
        ptr1 += 8;
        ptr2 += 8;
    }
    
    // Handle remaining bytes
    while (*ptr1 && *ptr2 && *ptr1 == *ptr2)
    {
        ptr1++;
        ptr2++;
    }
    
    return (*ptr1 - *ptr2);
}