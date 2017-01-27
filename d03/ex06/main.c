

#include <stdio.h>

int	ft_strlen(char *str);

int main()
{
	int len = ft_strlen("asdf");
	printf("result: %d (should be 4)\n", len);

	return 0;
}
