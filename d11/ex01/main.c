

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data);

int main()
{
	t_list* my_list = NULL;
	ft_list_push_back(&my_list, "hello world!");
	ft_list_push_back(&my_list, "asdf");
	ft_list_push_back(&my_list, "qwer");

	for(t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%s\n", (char*)iter->data);

	return 0;
}
