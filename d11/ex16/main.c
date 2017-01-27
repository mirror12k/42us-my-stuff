

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());

int main(int argc, char** argv)
{
	t_list* my_list = 0;
	for (int i = 1; i < argc; i++)
		ft_sorted_list_insert(&my_list, argv[i], (int(*)())strcmp);
	for (t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%s\n", (char*)iter->data);

	return 0;
}
