/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 00:00:00 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/25 00:00:00 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLICE_H
# define SLICE_H

# include <stddef.h>

typedef struct s_slice
{
	void	*data;
	size_t	start;
	size_t	len;
	size_t	elem_size;
	int		owned;
}	t_slice;

/* Creation & Management */
t_slice	*slice_create(const void *array, size_t start, size_t len, size_t elem_size);
t_slice	*slice_create_view(const void *array, size_t start, size_t len, size_t elem_size);
void	slice_free(t_slice *slice);

/* Access & Information */
void	*slice_get(t_slice *slice, size_t index);
size_t	slice_len(t_slice *slice);
size_t	slice_capacity(t_slice *slice);
int		slice_is_empty(t_slice *slice);

/* Operations */
t_slice	*slice_subslice(t_slice *slice, size_t start, size_t len);
void	*slice_to_array(t_slice *slice);

#endif
