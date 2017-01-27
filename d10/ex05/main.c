

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int));

int greater(int a, int b)
{
	return b - a;
}

int main()
{
	int test[] = {1,2,3,4,0};
	printf("is sorted? %d\n", ft_is_sort(test, 5, greater));

	return 0;
}
