

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ft_btree.h"

int	btree_level_count(t_btree *root);

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
	t_btree* tree = CN("qwer");
	tree->left = CN("asdf");
	tree->right = CN("zxcv");
	tree->left->left = CN("aaaa");
	tree->left->right = CN("doop");

	crap_a_tree(tree, 0);

	printf("level count: %d\n", btree_level_count(tree));
	printf("level count left: %d\n", btree_level_count(tree->left));
	printf("level count right: %d\n", btree_level_count(tree->right));

	return 0;
}
