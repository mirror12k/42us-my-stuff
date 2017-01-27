

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());


int starts_with(char *str, char *ref)
{
	return str[0] - ref[0];
}

int main()
{
	t_list *my_list = 0;
	t_list *found;
	
	found = ft_list_find(my_list, "a", (int(*)())starts_with);
	printf("%p\n", found);

	my_list = ft_create_elem("asdf");
	found = ft_list_find(my_list, "a", (int(*)())starts_with);
	printf("%s\n", (char*)found->data);

	my_list = ft_create_elem("qwer");
	my_list->next = ft_create_elem("asdf");
	my_list->next->next = ft_create_elem("zxcv");
	found = ft_list_find(my_list, "a", (int(*)())starts_with);
	printf("%s\n", (char*)found->data);

	found = ft_list_find(my_list, "z", (int(*)())starts_with);
	printf("%s\n", (char*)found->data);

	found = ft_list_find(my_list, "q", (int(*)())starts_with);
	printf("%s\n", (char*)found->data);

	found = ft_list_find(my_list, "d", (int(*)())starts_with);
	printf("%p\n", found);

	return 0;
}
