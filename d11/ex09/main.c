

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void*));

void	map_num(int* i)
{
	*i += 5;
}

int main()
{
	int i = 15, i2 = 25, i3 = -35;
	t_list* my_list;
	my_list = ft_create_elem(&i);
	my_list->next = ft_create_elem(&i2);
	my_list->next->next = ft_create_elem(&i3);
	ft_list_foreach(my_list, (void(*)(void*))map_num);
	
	for (t_list* iter = my_list; iter != 0; iter = iter->next)
		printf("%d\n", *(int*)(iter->data));

	return 0;
}
