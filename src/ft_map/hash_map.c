/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:21:42 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/02 23:38:44 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "hash_map.h"

static unsigned int	hash(const char *key, int size)
{
    unsigned long	hash;
    int				c;

    hash = 5381; // why 5381? it's a magic number from the original djb2 algorithm
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return (hash % size);
}

t_hash_map	*hash_map_create(int size)
{
    t_hash_map	*map;
    int			i;

    map = malloc(sizeof(t_hash_map));
    if (!map)
        return (NULL);
    map->buckets = malloc(sizeof(t_node *) * size);
    if (!map->buckets)
    {
        free(map);
        return (NULL);
    }
    i = 0;
    while (i < size)
    {
        map->buckets[i] = NULL;
        i++;
    }
    map->size = size;
    map->count = 0;
    return (map);
}

void	hash_map_insert(t_hash_map *map, char *key, void *value)
{
    unsigned int	index;
    t_node			*new_node;
    t_node			*current;

    if (!map || !key)
        return ;
    index = hash(key, map->size);
    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return ;
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    if (!map->buckets[index])
    {
        map->buckets[index] = new_node;
    }
    else
    {
        current = map->buckets[index];
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
    map->count++;
}

void	*hash_map_get(t_hash_map *map, char *key)
{
    unsigned int	index;
    t_node			*current;

    if (!map || !key)
        return (NULL);
    index = hash(key, map->size);
    current = map->buckets[index];
    while (current)
    {
        if (current->key && strcmp(current->key, key) == 0)
            return (current->value);
        current = current->next;
    }
    return (NULL);
}

void	hash_map_remove(t_hash_map *map, char *key)
{
    unsigned int	index;
    t_node			*current;
    t_node			*prev;

    if (!map || !key)
        return ;
    index = hash(key, map->size);
    current = map->buckets[index];
    prev = NULL;
    while (current)
    {
        if (current->key && strcmp(current->key, key) == 0)
        {
            if (prev)
                prev->next = current->next;
            else
                map->buckets[index] = current->next;
            free(current);
            map->count--;
            return ;
        }
        prev = current;
        current = current->next;
    }
}


