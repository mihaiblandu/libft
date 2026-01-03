/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:20:32 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/02 23:37:23 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_MAP_H
# define HASH_MAP_H

typedef struct s_node
{
    char            *key;
    void            *value;
    struct s_node   *next;
}   t_node;

typedef struct s_hash_map
{
    t_node          **buckets;
    int             size;      // Number of buckets
    int             count;     // Number of items currently stored
}   t_hash_map;

// Function Prototypes
t_hash_map  *hash_map_create(int size);
void        hash_map_insert(t_hash_map *map, char *key, void *value);
void        *hash_map_get(t_hash_map *map, char *key);

void        hash_map_remove(t_hash_map *map, char *key);

#endif