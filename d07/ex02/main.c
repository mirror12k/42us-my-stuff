

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_ultimate_range(int **range, int min, int max);

int main()
{
	int* range;
	int size = ft_ultimate_range(&range, 5, 10);
	for (int i = 0; i < size; i++)
		printf("[%d] %d, ", i, range[i]);
	printf("(%d) 0x%x\n", size, (unsigned int)range);

	return 0;
}
