
#include <unistd.h>
#include <stdlib.h>

#include "ft_list.h"

int		ft_putchar(char c);

int ft_putchar(char c)
{
	return write(STDOUT_FILENO, &c, 1);
}

t_list	*ft_create_elem(void *data)
{
	t_list *link;

	link = malloc(sizeof(t_list));
	link->next = NULL;
	link->data = data;
	return (link);
}
