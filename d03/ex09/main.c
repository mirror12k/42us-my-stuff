

#include <stdio.h>

void	ft_sort_integer_table(int *tab, int size);

int main()
{
	int size = 7;
	int table[size];
	table[0] = 4;
	table[1] = 2;
	table[2] = 3;
	table[3] = 1;
	table[4] = 5;
	table[5] = 0;
	table[6] = -10;


	ft_sort_integer_table(table, size);

	int i;
	for (i = 0; i < size; i++)
		printf("[%d] : %d\n", i, table[i]);

	return 0;
}
