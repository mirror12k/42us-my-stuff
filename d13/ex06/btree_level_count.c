/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:08:57 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/27 12:22:55 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int level_left;
	int level_right;

	if (root == 0)
		return (-1);
	level_left = btree_level_count(root->left);
	level_right = btree_level_count(root->right);
	if (level_left > level_right)
		return (level_left + 1);
	else
		return (level_right + 1);
}
