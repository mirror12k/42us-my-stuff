

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	*ft_range(int min, int max);

int main()
{
	int* range = ft_range(0, 5);

	for (int i = 0; i < 5; i++)
		printf("[%d] %d, ", i, range[i]);
	printf("\n");

	int* range2 = ft_range(-20, -15);

	for (int i = 0; i < 5; i++)
		printf("[%d] %d, ", i, range2[i]);
	printf("\n");
	
	int* range3 = ft_range(0, -200);
	printf("%x\n", (unsigned int)range3);

	return 0;
}
