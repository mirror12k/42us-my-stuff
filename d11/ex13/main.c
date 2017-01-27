

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);

int main()
{
	t_list* list1 = 0;
	t_list* list2 = 0;

	ft_list_merge(&list1, list2);
	printf("list: ");
	for (t_list* iter = list1; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	list2 = ft_create_elem("asdf");
	ft_list_merge(&list1, list2);
	printf("list: ");
	for (t_list* iter = list1; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	list2 = ft_create_elem("qwer");
	list2->next = ft_create_elem("zxcv");
	ft_list_merge(&list1, list2);
	printf("list: ");
	for (t_list* iter = list1; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	list2 = 0;
	ft_list_merge(&list1, list2);
	printf("list: ");
	for (t_list* iter = list1; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");



	return 0;
}
