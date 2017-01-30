

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void*, void*));

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

int	starts_with(char* str, char* ref)
{
	printf("debug %s vs %s\n", str, ref);
	return (*str - *ref);
}

#define CN(item) btree_create_node(item)

int main()
{
	t_btree* tree = CN("qwer");
	tree->left = CN("asdf");
	tree->right = CN("zxcv");
	tree->left->left = CN("aaaa");
	tree->left->right = CN("doop");
	char* found = btree_search_item(tree, "q", (int(*)(void*, void*))starts_with);
	printf("found: %s\n", found);

	return 0;
}
