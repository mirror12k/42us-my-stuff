

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int main()
{
	char dest[256];
	dest[4] = 0;
	printf("asdf: %s\n", ft_strncpy(dest, "asdf", 4));

	dest[6] = 0;
	printf("qwerty: %s\n", ft_strncpy(dest, "qwerty", 6));

	printf("zxc: %s\n", ft_strncpy(dest, "zxc", 4));


	return 0;
}
