

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);

int main()
{
	t_list* my_list = NULL;
	ft_list_push_front(&my_list, "hello");
	ft_list_push_front(&my_list, "world");
	ft_list_push_front(&my_list, "!");
	ft_list_push_front(&my_list, "asdf");

	for(t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%s\n", (char*)iter->data);

	return 0;
}
