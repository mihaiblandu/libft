/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:22:04 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/02 22:37:51 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
** Create a new trie node
*/
t_trie	*trie_create_node(void)
{
	t_trie	*node;
	int		i;

	node = (t_trie *)malloc(sizeof(t_trie));
	if (!node)
		return (NULL);
	
	i = 0;
	while (i < TRIE_ALPHABET_SIZE)
	{
		node->children[i] = NULL;
		i++;
	}
	node->value = NULL;
	node->is_end = false;
	return (node);
}

/*
** Helper function to get character index (0-25 for 'a'-'z')
*/
static int	trie_get_char_index(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a');
	if (c >= 'A' && c <= 'Z')
		return (c - 'A');
	return (-1);
}

/*
** Insert a key-value pair into the trie
*/
bool	trie_insert(t_trie *root, const char *key, void *value)
{
	t_trie	*current;
	int		index;
	int		i;

	if (!root || !key)
		return (false);
	
	current = root;
	i = 0;
	while (key[i])
	{
		index = trie_get_char_index(key[i]);
		if (index == -1)
			return (false);
		
		if (!current->children[index])
		{
			current->children[index] = trie_create_node();
			if (!current->children[index])
				return (false);
		}
		current = current->children[index];
		i++;
	}
	
	current->is_end = true;
	current->value = value;
	return (true);
}

/*
** Search for a key in the trie and return its value
*/
void	*trie_search(t_trie *root, const char *key)
{
	t_trie	*current;
	int		index;
	int		i;

	if (!root || !key)
		return (NULL);
	
	current = root;
	i = 0;
	while (key[i])
	{
		index = trie_get_char_index(key[i]);
		if (index == -1 || !current->children[index])
			return (NULL);
		current = current->children[index];
		i++;
	}
	
	if (current->is_end)
		return (current->value);
	return (NULL);
}

/*
** Helper function to check if a node has no children
*/
static bool	trie_is_empty(t_trie *node)
{
	int	i;

	if (!node)
		return (true);
	
	i = 0;
	while (i < TRIE_ALPHABET_SIZE)
	{
		if (node->children[i])
			return (false);
		i++;
	}
	return (true);
}

/*
** Helper function for recursive deletion
*/
static bool	trie_delete_helper(t_trie **node, const char *key, size_t depth)
{
	int		index;
	bool	should_free;

	if (!*node)
		return (false);
	
	if (depth == strlen(key))
	{
		if (!(*node)->is_end)
			return (false);
		
		(*node)->is_end = false;
		(*node)->value = NULL;
		
		if (trie_is_empty(*node))
		{
			free(*node);
			*node = NULL;
		}
		return (true);
	}
	
	index = trie_get_char_index(key[depth]);
	if (index == -1 || !(*node)->children[index])
		return (false);
	
	should_free = trie_delete_helper(&((*node)->children[index]), key, depth + 1);
	
	if (should_free && trie_is_empty(*node) && !(*node)->is_end)
	{
		free(*node);
		*node = NULL;
		return (true);
	}
	return (should_free);
}

/*
** Delete a key from the trie
*/
bool	trie_delete(t_trie **root, const char *key)
{
	if (!root || !*root || !key)
		return (false);
	
	return (trie_delete_helper(root, key, 0));
}

/*
** Free the entire trie
*/
void	trie_free(t_trie **root, void (*del)(void *))
{
	int	i;

	if (!root || !*root)
		return;
	
	i = 0;
	while (i < TRIE_ALPHABET_SIZE)
	{
		if ((*root)->children[i])
			trie_free(&((*root)->children[i]), del);
		i++;
	}
	
	if (del && (*root)->value)
		del((*root)->value);
	
	free(*root);
	*root = NULL;
}
