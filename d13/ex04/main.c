

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void*, void*));

t_btree	*btree_create_node(void *item)
{
	t_btree *node;

	node = malloc(sizeof(t_btree));
	node->item = item;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void crap_a_tree(t_btree* root, int level)
{
	if (root != NULL)
	{
		for (int i = 0; i < level; i++)
			printf("-");
		printf(" %s\n", (char*)root->item);
		crap_a_tree(root->left, level + 1);
		crap_a_tree(root->right, level + 1);
	}
}

#define CN(item) btree_create_node(item)

int main()
{
	t_btree* tree = NULL;
	btree_insert_data(&tree, "qwer", (int(*)(void*,void*))strcmp);
	btree_insert_data(&tree, "asdf", (int(*)(void*,void*))strcmp);
	btree_insert_data(&tree, "zxcv", (int(*)(void*,void*))strcmp);
	btree_insert_data(&tree, "zz", (int(*)(void*,void*))strcmp);
	btree_insert_data(&tree, "vbnm", (int(*)(void*,void*))strcmp);
	btree_insert_data(&tree, "doop", (int(*)(void*,void*))strcmp);
	btree_insert_data(&tree, "aaaa", (int(*)(void*,void*))strcmp);
	
	crap_a_tree(tree, 0);
	return 0;
}
