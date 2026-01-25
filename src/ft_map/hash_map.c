/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:21:42 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/09 05:27:02 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

static unsigned int hash(const char *key)
{
	unsigned int	hash;
	int				i;

	hash = 0;
	i = 0;
	while (key[i])
	{
		hash = (hash * 31) + key[i];
		i++;
	}
	return (hash % MAP_SIZE);
}

// Create a new map
t_map *map_create(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	ft_bzero(map->buckets, sizeof(map->buckets));
	map->size = 0;
	return (map);
}

// Put key-value pair into map
void map_put(t_map *map, const char *key, void *value)
{
	unsigned int	index;
	t_map_entry		*entry;
	t_map_entry		*new_entry;

	if (!map || !key)
		return;
	index = hash(key);
	entry = map->buckets[index];
	
	// Check if key already exists
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
		{
			entry->value = value;  // Update existing value
			return;
		}
		entry = entry->next;
	}
	
	// Create new entry
	new_entry = malloc(sizeof(t_map_entry));
	if (!new_entry)
		return;
	new_entry->key = ft_strdup(key);
	if (!new_entry->key)
	{
		free(new_entry);
		return;
	}
	new_entry->value = value;
	new_entry->next = map->buckets[index];
	map->buckets[index] = new_entry;
	map->size++;
}

// Get value by key
void *map_get(t_map *map, const char *key)
{
	unsigned int	index;
	t_map_entry		*entry;

	if (!map || !key)
		return (NULL);
	index = hash(key);
	entry = map->buckets[index];
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
			return (entry->value);
		entry = entry->next;
	}
	return (NULL);
}

// Check if key exists
int map_contains(t_map *map, const char *key)
{
	unsigned int	index;
	t_map_entry		*entry;

	if (!map || !key)
		return (0);
	index = hash(key);
	entry = map->buckets[index];
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
			return (1);
		entry = entry->next;
	}
	return (0);
}

// Remove entry by key
void map_remove(t_map *map, const char *key)
{
	unsigned int	index;
	t_map_entry		*entry;
	t_map_entry		*prev;

	if (!map || !key)
		return;
	index = hash(key);
	entry = map->buckets[index];
	prev = NULL;
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
		{
			if (prev)
				prev->next = entry->next;
			else
				map->buckets[index] = entry->next;
			free(entry->key);
			free(entry);
			map->size--;
			return;
		}
		prev = entry;
		entry = entry->next;
	}
}

// Clear all entries
void map_clear(t_map *map)
{
	int			i;
	t_map_entry	*entry;
	t_map_entry	*next;

	if (!map)
		return;
	i = 0;
	while (i < MAP_SIZE)
	{
		entry = map->buckets[i];
		while (entry)
		{
			next = entry->next;
			free(entry->key);
			free(entry);
			entry = next;
		}
		map->buckets[i] = NULL;
		i++;
	}
	map->size = 0;
}

// Free the map
void map_free(t_map *map)
{
	if (!map)
		return;
	map_clear(map);
	free(map);
}

// Get map size
int map_size(t_map *map)
{
	if (!map)
		return (0);
	return (map->size);
}