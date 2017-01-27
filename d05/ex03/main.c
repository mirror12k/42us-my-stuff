

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int main()
{
	char test1[256];
	printf("asdf: %s\n", ft_strcpy(test1, "asdf"));
	printf("qwerty: %s\n", ft_strcpy(test1, "qwerty"));
	printf("zxc: %s\n", ft_strcpy(test1, "zxc"));
	printf(": %s\n", ft_strcpy(test1, ""));

	return 0;
}
