

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_foreach(int *tab, int length, void(*f)(int));

void dump_int(int v)
{
	printf("%d\n", v);
}

int main()
{
	int test[] = {1,2,3,4,5};
	ft_foreach(test, 5, dump_int);

	return 0;
}
