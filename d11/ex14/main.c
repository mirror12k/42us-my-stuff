

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)());

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *iter;

	if (*begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
	{
		iter = *begin_list;
		while (iter->next != 0)
			iter = iter->next;
		iter->next = ft_create_elem(data);
	}
}

int main(int argc, char** argv)
{
	t_list* my_list = 0;
	for (int i = 1; i < argc; i++)
		ft_list_push_back(&my_list, argv[i]);

	ft_list_sort(&my_list, (int(*)())strcmp);
	for (t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%s\n", (char*)iter->data);

	return 0;
}
