

#include <stdio.h>

void ft_swap(int *a, int *b);

int main()
{
	int a = 42;
	int b = 0xCAFE;
	ft_swap(&a, &b);

	printf("result: %x %d (should be cafe, 42)\n", a, b);

	return 0;
}
