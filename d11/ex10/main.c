

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void*), void *data_ref, int (*cmp)());

void out_string(char *str)
{
	printf("%s\n", str);
}

int starts_with(char *str, char *ref)
{
	return str[0] - ref[0];
}

int main()
{
	t_list* list;

	list = ft_create_elem("asdf");
	list->next = ft_create_elem("qwer");
	list->next->next = ft_create_elem("zxcv");
	list->next->next->next = ft_create_elem("a");
	list->next->next->next->next = ft_create_elem("alpha");

	
	ft_list_foreach_if(list, (void(*)(void*))out_string, "a", (int(*)())starts_with);

	return 0;
}
