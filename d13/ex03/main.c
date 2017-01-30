

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*apply)(void*));

t_btree	*btree_create_node(void *item)
{
	t_btree *node;

	node = malloc(sizeof(t_btree));
	node->item = item;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

#define CN(item) btree_create_node(item)

void	print_node_item(void* s)
{
	printf("node: %s\n", (char*)s);
}

int main()
{
	t_btree* tree = CN("A");
	tree->left = CN("B");
	tree->right = CN("C");
	tree->right->right = CN("D");
	btree_apply_suffix(tree, print_node_item);

	return 0;
}
