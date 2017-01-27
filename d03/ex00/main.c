
#include <stdio.h>

void ft_ft(int *nbr);

int main()
{
	int v = 15;
	ft_ft(&v);

	printf("result: %d\n", v);

	return 0;
}
