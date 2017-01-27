

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_count_if(char **tab, int(*f)(char*));

int starts_with_a(char* str)
{
	return str[0] == 'a';
}

int main(int argc, char** argv)
{
	if (argc > 0)
		printf("starts with a: %d\n", ft_count_if(argv, starts_with_a));

	return 0;
}
