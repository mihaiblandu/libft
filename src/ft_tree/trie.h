/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:22:04 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/02 22:28:56 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_H
# define TRIE_H

# include <stdbool.h>

/*
** Trie (Prefix Tree)
** Alphabet size is typically 26 for 'a'-'z' or 128/256 for ASCII
*/
#define TRIE_ALPHABET_SIZE 26

typedef struct s_trie
{
	struct s_trie	*children[TRIE_ALPHABET_SIZE];
	void *value; // Poate stoca date asociate cu cuvântul
	bool is_end; // Marchează dacă aici se termină un cuvânt valid
}					t_trie;

/* ** Trie Functions */
t_trie				*trie_create_node(void);
bool				trie_insert(t_trie *root, const char *key, void *value);
void				*trie_search(t_trie *root, const char *key);
bool				trie_delete(t_trie **root, const char *key);
void				trie_free(t_trie **root, void (*del)(void *));

#endif