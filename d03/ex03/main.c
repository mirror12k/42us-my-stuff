

#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod);

int main()
{
	int div = 0;
	int mod = 0;
	ft_div_mod(42, 4, &div, &mod);

	printf("result: %d, %d (should be 10, 2)\n", div, mod);

	return 0;
}
