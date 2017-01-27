
#include "ft_abs.h"
#include <stdio.h>

int main()
{
	printf("%d\n", ABS(15));
	printf("%d\n", ABS(-25));
	printf("%d\n", ABS(0));
	printf("%d\n", ABS(2147483647));
	printf("%d\n", ABS(-2147483647));
	printf("%d\n", ABS(-2147483648));
	return 0;
}
