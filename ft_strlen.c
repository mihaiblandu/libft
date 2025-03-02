/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihai.blandu <mihai.blandu@ctif.gov.md>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:45:58 by mihai.bland       #+#    #+#             */
/*   Updated: 2024/02/27 21:27:06 by mihai.bland      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

size_t ft_strlen(const char *s) {
	const char *str;

	str = s;
    while ((uintptr_t)(s) & (sizeof(long) - 1)) {
        if (*s == '\0') 
            return s - str;
		s++;
	}

    const long *w;

	w = (const long *)s;
	while (!((*w - 0x0101010101010101L) & ~(*w) & 0x8080808080808080L))
		w++;

	s = (const char *)w;
	while (*s)
		s++;
	return s - str;
}