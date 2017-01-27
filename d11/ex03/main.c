

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

int	ft_list_size(t_list *being_list);

int main()
{
	t_list* my_list = NULL;
	printf("%d\n", ft_list_size(my_list));
	my_list = ft_create_elem("asdf");
	printf("%d\n", ft_list_size(my_list));
	my_list->next = ft_create_elem("qwer");
	printf("%d\n", ft_list_size(my_list));
	my_list->next->next = ft_create_elem("zxcv");
	my_list->next->next->next = ft_create_elem("uiop");
	printf("%d\n", ft_list_size(my_list));
	printf("%d\n", ft_list_size(my_list));

	return 0;
}
