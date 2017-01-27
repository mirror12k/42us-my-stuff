

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_any(char **tab, int(*f)(char*));

int is_long_str(char* s)
{
	return strlen(s) > 16;
}

int main(int argc, char** argv)
{
	if (argc > 0)
		printf("has long? %d\n", ft_any(argv, is_long_str));

	return 0;
}
