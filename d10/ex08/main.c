

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_advanced_sort_wordtab(char **tab, int(*cmp)(char*,char*));

int	chrcmp(char* s1, char* s2)
{
	return (*s1 - *s2);
}

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		ft_advanced_sort_wordtab(argv + 1, chrcmp);
		for (char** iter = argv + 1; *iter != 0; iter++)
			printf("%s\n", *iter);
	}

	return 0;
}
