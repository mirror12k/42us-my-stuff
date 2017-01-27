

#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b);

int main()
{
	int a = 42;
	int b = 4;
	ft_ultimate_div_mod(&a, &b);

	printf("result: %d, %d (should be 10, 2)\n", a, b);

	return 0;
}
