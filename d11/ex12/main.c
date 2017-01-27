

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

int starts_with(char *str, char *ref)
{
	return str[0] - ref[0];
}

int main()
{
	t_list* my_list;
	my_list = ft_create_elem("asdf");
	my_list->next = ft_create_elem("qwer");
	my_list->next->next = ft_create_elem("zxcv");
	my_list->next->next->next = ft_create_elem("alpha");
	my_list->next->next->next->next = ft_create_elem("qual");

	printf("list: ");
	for (t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	ft_list_remove_if(&my_list, "a", (int(*)())starts_with);
	printf("list: ");
	for (t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	ft_list_remove_if(&my_list, "a", (int(*)())starts_with);
	printf("list: ");
	for (t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	ft_list_remove_if(&my_list, "z", (int(*)())starts_with);
	printf("list: ");
	for (t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	ft_list_remove_if(&my_list, "a", (int(*)())starts_with);
	printf("list: ");
	for (t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	ft_list_remove_if(&my_list, "q", (int(*)())starts_with);
	printf("list: ");
	for (t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%s,", (char*)iter->data);
	printf("\n");

	return 0;
}
