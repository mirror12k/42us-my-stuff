

#include <stdio.h>

void ft_ultimate_ft(int *********nbr);

int main()
{
	int a = 15;
	int* b = &a;
	int** c = &b;
	int*** d = &c;
	int**** e = &d;
	int***** f = &e;
	int****** g = &f;
	int******* h = &g;
	int******** i = &h;
	int********* j = &i;

	ft_ultimate_ft(j);

	printf("result: %d\n", a);

	return 0;
}
