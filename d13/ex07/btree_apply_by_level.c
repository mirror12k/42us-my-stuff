/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:35:22 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/27 14:46:57 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_btree.h"

void	btree_apply_to_nodes(t_btree **nodes, int level,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int i;

	i = 0;
	while (*nodes != NULL)
	{
		applyf(nodes[0]->item, level, i == 0);
		i++;
		nodes++;
	}
}

int		btree_count_next_level(t_btree **nodes)
{
	int count;

	count = 0;
	while (*nodes != NULL)
	{
		if (nodes[0]->left)
			count++;
		if (nodes[0]->right)
			count++;
		nodes++;
	}
	return (count);
}

t_btree	**btree_load_next_level(t_btree **nodes)
{
	int		next_count;
	t_btree	**new_nodes;
	t_btree	**new_iter;

	next_count = btree_count_next_level(nodes);
	new_nodes = malloc(sizeof(t_btree*) * (next_count + 1));
	new_iter = new_nodes;
	while (*nodes != NULL)
	{
		if (nodes[0]->left)
			*new_iter++ = nodes[0]->left;
		if (nodes[0]->right)
			*new_iter++ = nodes[0]->right;
		nodes++;
	}
	*new_iter = NULL;
	return (new_nodes);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_btree	**nodes;
	t_btree	**next_nodes;
	int		level;

	level = 0;
	nodes = malloc(sizeof(t_btree*) * 2);
	nodes[0] = root;
	nodes[1] = NULL;
	while (*nodes != NULL)
	{
		btree_apply_to_nodes(nodes, level, applyf);
		next_nodes = btree_load_next_level(nodes);
		free(nodes);
		nodes = next_nodes;
		level++;
	}
	free(nodes);
}
