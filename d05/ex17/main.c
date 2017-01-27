

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, int nb);

int main()
{
	char test1 [256] = "asdf";
	printf("asdf + qwerty (4): %s\n", ft_strncat(test1, "qwerty", 4));

	return 0;
}
