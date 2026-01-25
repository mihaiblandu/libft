/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 00:00:00 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/25 00:00:00 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slice.h"
#include "../libft.h"

t_slice	*slice_create(const void *array, size_t start, size_t len, size_t elem_size)
{
	t_slice	*slice;
	void	*data;

	if (!array || elem_size == 0)
		return (NULL);
	slice = malloc(sizeof(t_slice));
	if (!slice)
		return (NULL);
	data = ft_slice(array, start, len, elem_size);
	if (!data)
	{
		free(slice);
		return (NULL);
	}
	slice->data = data;
	slice->start = 0;
	slice->len = len;
	slice->elem_size = elem_size;
	slice->owned = 1;
	return (slice);
}

t_slice	*slice_create_view(const void *array, size_t start, size_t len, size_t elem_size)
{
	t_slice	*slice;

	if (!array || elem_size == 0)
		return (NULL);
	slice = malloc(sizeof(t_slice));
	if (!slice)
		return (NULL);
	slice->data = (void *)array;
	slice->start = start;
	slice->len = len;
	slice->elem_size = elem_size;
	slice->owned = 0;
	return (slice);
}

void	slice_free(t_slice *slice)
{
	if (!slice)
		return;
	if (slice->owned && slice->data)
		free(slice->data);
	free(slice);
}

void	*slice_get(t_slice *slice, size_t index)
{
	if (!slice || index >= slice->len)
		return (NULL);
	if (slice->owned)
		return ((char *)slice->data + (index * slice->elem_size));
	return ((char *)slice->data + ((slice->start + index) * slice->elem_size));
}

size_t	slice_len(t_slice *slice)
{
	if (!slice)
		return (0);
	return (slice->len);
}

size_t	slice_capacity(t_slice *slice)
{
	return (slice_len(slice));
}

int	slice_is_empty(t_slice *slice)
{
	if (!slice)
		return (1);
	return (slice->len == 0);
}

t_slice	*slice_subslice(t_slice *slice, size_t start, size_t len)
{
	if (!slice || start >= slice->len)
		return (NULL);
	if (start + len > slice->len)
		len = slice->len - start;
	if (slice->owned)
		return (slice_create_view(slice->data, start, len, slice->elem_size));
	return (slice_create_view(slice->data, slice->start + start, len, slice->elem_size));
}

void	*slice_to_array(t_slice *slice)
{
	void	*array;
	size_t	i;

	if (!slice)
		return (NULL);
	if (slice->owned && slice->start == 0)
		return (slice->data);
	array = malloc(slice->len * slice->elem_size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < slice->len)
	{
		ft_memcpy((char *)array + (i * slice->elem_size),
			slice_get(slice, i), slice->elem_size);
		i++;
	}
	return (array);
}
