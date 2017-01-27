

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);

int main()
{
	t_list* my_list;
	my_list = ft_create_elem("0th");
	my_list->next = ft_create_elem("1st");
	my_list->next->next = ft_create_elem("2nd");
	my_list->next->next->next = ft_create_elem("3rd");
	printf("0: %s\n", (char*)(ft_list_at(my_list, 0)->data));
	printf("1: %s\n", (char*)(ft_list_at(my_list, 1)->data));
	printf("2: %s\n", (char*)(ft_list_at(my_list, 2)->data));
	printf("2: %s\n", (char*)(ft_list_at(my_list, 3)->data));
	printf("4: %p\n", ft_list_at(my_list, 4));
	printf("15: %p\n", ft_list_at(0, 15));

	return 0;
}
