

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ft_btree.h"

t_btree	*btree_create_node(void *item);

int main()
{
	t_btree *node = btree_create_node("asdf");
	printf("%p %p '%s'\n", node->left, node->right, node->item);
	return 0;
}
