

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int main()
{
	char test1 [256];
	printf("asdf (5): %d\n", ft_strlcpy(test1, "asdf", 5));
	printf("%s\n", test1);
	printf("asdf (4): %d\n", ft_strlcpy(test1, "asdf", 4));
	printf("%s\n", test1);

	return 0;
}
