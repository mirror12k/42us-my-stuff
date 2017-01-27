

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list);

int main()
{
	t_list* my_list = 0;
	ft_list_clear(&my_list);
	printf("clear: %p\n", my_list);
	my_list = ft_create_elem("asdf");
	printf("%p\n", my_list);
	ft_list_clear(&my_list);
	printf("clear: %p\n", my_list);
	my_list = ft_create_elem("asdf");
	printf("%p\n", my_list);
	my_list->next = ft_create_elem("qwer");
	ft_list_clear(&my_list);
	printf("clear: %p\n", my_list);

	return 0;
}
