

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list);

int main()
{
	t_list* my_list = 0;
	printf("%p\n", ft_list_last(my_list));
	my_list = ft_create_elem("first");
	printf("%s\n", (char*)(ft_list_last(my_list))->data);
	my_list->next = ft_create_elem("second");
	printf("%s\n", (char*)(ft_list_last(my_list))->data);
	my_list->next->next = ft_create_elem("third");
	my_list->next->next->next = ft_create_elem("fourth");
	printf("%s\n", (char*)(ft_list_last(my_list))->data);

	return 0;
}
