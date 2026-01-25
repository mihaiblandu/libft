/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:28:43 by mihai.bland       #+#    #+#             */
/*   Updated: 2026/01/09 06:05:35 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char *ft_strchr(const char *s, int c)
{
    const char *ptr = s;
    unsigned long long chunk;
    unsigned long long match_pattern;
    unsigned char target = (unsigned char)c;
    
    // Handle null terminator case upfront
    if (target == '\0')
    {
        while (*s)
            s++;
        return ((char *)s);
    }
    
    // Create 8-byte pattern of target character
    match_pattern = target;
    match_pattern |= match_pattern << 8;
    match_pattern |= match_pattern << 16;
    match_pattern |= match_pattern << 32;
    
    // Process byte-by-byte until aligned
    while (((unsigned long)ptr & 7) && *ptr)
    {
        if (*ptr == target)
            return ((char *)ptr);
        ptr++;
    }
    
    // Process 64-bit chunks
    while (1)
    {
        chunk = *(unsigned long long *)ptr;
        
        // Check for null byte
        if (((chunk - 0x0101010101010101ULL) & ~chunk & 0x8080808080808080ULL))
            break;
        
        // Check for match in chunk
        unsigned long long xor_chunk = chunk ^ match_pattern;
        if (((xor_chunk - 0x0101010101010101ULL) & ~xor_chunk & 0x8080808080808080ULL))
        {
            // Found match - find exact byte
            for (int i = 0; i < 8; i++)
                if (((char *)ptr)[i] == target)
                    return ((char *)(ptr + i));
        }
        
        ptr += 8;
    }
    
    // Handle remaining bytes
    while (*ptr)
    {
        if (*ptr == target)
            return ((char *)ptr);
        ptr++;
    }
    
    return (NULL);
}

char *ft_strrchr(const char *s, int c)
{
    const char *last = NULL;
    const char *ptr = s;
    unsigned long long chunk;
    unsigned long long match_pattern;
    unsigned char target = (unsigned char)c;
    
    // Handle null terminator case upfront
    if (target == '\0')
    {
        while (*s)
            s++;
        return ((char *)s);
    }
    
    // Create 8-byte pattern of target character
    match_pattern = target;
    match_pattern |= match_pattern << 8;
    match_pattern |= match_pattern << 16;
    match_pattern |= match_pattern << 32;
    
    // Process 8 bytes at a time while aligned
    while (((unsigned long)ptr & 7) && *ptr)
    {
        if (*ptr == target)
            last = ptr;
        ptr++;
    }
    
    // Process 64-bit chunks
    while (1)
    {
        chunk = *(unsigned long long *)ptr;
        
        // Check for null byte (SWAR technique)
        if (((chunk - 0x0101010101010101ULL) & ~chunk & 0x8080808080808080ULL))
            break;
        
        // Check for matches in chunk
        unsigned long long xor_chunk = chunk ^ match_pattern;
        if (((xor_chunk - 0x0101010101010101ULL) & ~xor_chunk & 0x8080808080808080ULL))
        {
            // Found match(es) - check byte by byte
            for (int i = 0; i < 8; i++)
                if (((char *)ptr)[i] == target)
                    last = ptr + i;
        }
        
        ptr += 8;
    }
    
    // Handle remaining bytes
    while (*ptr)
    {
        if (*ptr == target)
            last = ptr;
        ptr++;
    }
    
    return ((char *)last);
}


char *ft_strchrnul(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}