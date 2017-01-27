

#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int main()
{
	char test [256] = "asdf";
	printf("asdf + qwerty: %s\n", ft_strcat(test, "qwerty"));

	return 0;
}
