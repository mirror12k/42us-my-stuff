

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	*ft_map(int *tab, int length, int(*f)(int));

int inc_int(int n)
{
	return n + 5;
}

int main()
{
	int test[] = {1,2,3,15,25};
	int* res = ft_map(test, 5, inc_int);

	for (int i = 0; i < 5; i++)
		printf("%d\n", res[i]);

	return 0;
}
