

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
	char test1 [16] = "asdf";
	printf("asdf + qwerty: %d\n", ft_strlcat(test1, "qwerty", 16));
	printf("%s\n", test1);
	printf("asdfqwerty + : %d\n", ft_strlcat(test1, "", 16));
	printf("%s\n", test1);
	printf("asdfqwerty + zxcv: %d\n", ft_strlcat(test1, "zxcv", 16));
	printf("%s\n", test1);
	printf("asdfqwertyzxcv + uiop: %d\n", ft_strlcat(test1, "uiop", 16));
	printf("%s\n", test1);
	printf("asdfqwertyzxcvu + uiop: %d\n", ft_strlcat(test1, "uiop", 10));
	printf("%s\n", test1);

	return 0;
}
