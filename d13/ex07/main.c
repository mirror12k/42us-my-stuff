

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ft_btree.h"

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

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

void print_node(void* item, int level, int is_first)
{
	for (int i = 0; i < level; i++)
		printf("-");
	if (is_first)
		printf("*");
	else
		printf(" ");
	printf("%s\n", (char*)item);
}

int main()
{
	t_btree* tree = CN("A");
	tree->left = CN("B");
	tree->right = CN("C");
	tree->right->right = CN("D");
	tree->right->left = CN("E");
	tree->left->left = CN("F");
	
	btree_apply_by_level(tree, print_node);

	return 0;
}
