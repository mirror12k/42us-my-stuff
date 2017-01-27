

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_print_words_tables(char **tab);

int main(int argc, char** argv)
{
	printf("%d\n", argc);
	ft_print_words_tables(argv + 1);

	return 0;
}
