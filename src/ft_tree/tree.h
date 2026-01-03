/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:39:42 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/01 18:45:22 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

/*
** ============================
** Structures Definition
** ============================
*/
// Binary Search Tree (BST) Node
typedef struct s_btree
{
	int					id;
	void				*value;
	struct s_btree		*left;
	struct s_btree		*right;
}						t_btree;

// AVL Tree Node (Adelson-Velsky and Landis)
typedef struct s_avltree
{
	int					id;
	void				*value;
	struct s_avltree	*left;
	struct s_avltree	*right;
	int					height;
}						t_avltree;

// N-ary Tree Node (General Tree)
typedef struct s_gtree
{
	int					id;
	void				*value;
	struct s_gtree		*parent;
	struct s_gtree		**children;
	int					child_count;
	int					capacity;
}						t_gtree;

// B-Tree Node (Balanced M-way Tree)
typedef struct s_btree_b
{
	int					*keys;
	void				**values;
	struct s_btree_b	**children;
	int					key_count;
	bool				is_leaf;
}						t_btree_b;

/*
** ============================
** Function Prototypes
** ============================
*/

/* --- Binary Tree --- */
t_btree					*btree_create_node(int id, void *value);
int						btree_insert(t_btree **root, int id, void *value);
void					*btree_search(t_btree *root, int id);
int						btree_get_depth(t_btree *root);

/* --- Traversal (Generic) --- */
void					btree_apply_prefix(t_btree *root, void (*applyf)(int,
								void *));
void					btree_apply_infix(t_btree *root, void (*applyf)(int,
								void *));
void					btree_apply_suffix(t_btree *root, void (*applyf)(int,
								void *));

/* --- AVL Tree Specific --- */
t_avltree				*avltree_insert(t_avltree *node, int id, void *value);
t_avltree				*avltree_delete(t_avltree *root, int id,
							void (*del)(void *));

/* --- Memory Management --- */
void					btree_free(t_btree **root, void (*del)(void *));
void					gtree_free(t_gtree **root, void (*del)(void *));

#endif