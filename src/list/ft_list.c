/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:30:00 by mihaiblandu       #+#    #+#             */
/*   Updated: 2025/09/14 21:52:19 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/list.h"

#define INITIAL_CAPACITY 2

DynamicList *list_create(size_t element_size)
{
    DynamicList *list;

    if (element_size == 0)
        return (NULL);
    list = malloc(sizeof(DynamicList));
    if (!list)
        return (NULL);
    list->data = malloc(sizeof(void*) * INITIAL_CAPACITY);
    if (!list->data)
    {
        free(list);
        return (NULL);
    }
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->element_size = element_size;
    return (list);
}

int list_add(DynamicList *list, const void *element)
{
    void    **new_data;
    size_t  new_capacity;

    if (!list || !element)
        return (-1);
    if (list->size >= list->capacity)
    {
        new_capacity = list->capacity * 2;
        new_data = realloc(list->data, sizeof(void*) * new_capacity);
        if (!new_data)
            return (-1);
        list->data = new_data;
        list->capacity = new_capacity;
    }
    list->data[list->size] = malloc(list->element_size);
    if (!list->data[list->size])
        return (-1);
    memcpy(list->data[list->size], element, list->element_size);
    list->size++;
    return (0);
}

void *list_get(DynamicList *list, size_t index)
{
    if (!list || index >= list->size)
        return (NULL);
    return (list->data[index]);
}

int list_remove(DynamicList *list, size_t index)
{
    size_t i;

    if (!list || index >= list->size)
        return (-1);
    free(list->data[index]);
    i = index;
    while (i < list->size - 1)
    {
        list->data[i] = list->data[i + 1];
        i++;
    }
    list->size--;
    return (0);
}

size_t list_size(DynamicList *list)
{
    if (!list)
        return (0);
    return (list->size);
}

void list_free(DynamicList *list)
{
    size_t i;

    if (!list)
        return ;
    i = 0;
    while (i < list->size)
    {
        free(list->data[i]);
        i++;
    }
    free(list->data);
    free(list);
}