

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

int main()
{
	t_list *l1 = 0;
	t_list *l2;
	for (t_list* iter = l1; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	l2 = ft_create_elem("qwer");
	ft_sorted_list_merge(&l1, l2, (int(*)())strcmp);
	for (t_list* iter = l1; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	l2 = ft_create_elem("asdf");
	ft_sorted_list_merge(&l1, l2, (int(*)())strcmp);
	for (t_list* iter = l1; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	l2 = ft_create_elem("doop");
	l2->next = ft_create_elem("zxcv");
	ft_sorted_list_merge(&l1, l2, (int(*)())strcmp);

	for (t_list* iter = l1; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	return 0;
}
