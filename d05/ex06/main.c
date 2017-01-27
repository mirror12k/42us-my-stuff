

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int main()
{
	printf("asdf $ asde: %d\n", ft_strcmp("asdf", "asde"));
	printf("asdf $ asdf: %d\n", ft_strcmp("asdf", "asdf"));
	printf("asdf $ asdg: %d\n", ft_strcmp("asdf", "asdg"));

	printf("asdf $ asd: %d\n", ft_strcmp("asdf", "asd"));
	printf("asd $ asdf: %d\n", ft_strcmp("asd", "asdf"));
	printf(" $ asdf: %d\n", ft_strcmp("", "asdf"));
	printf("asdf $ : %d\n", ft_strcmp("asdf", ""));
	printf(" $ : %d\n", ft_strcmp("", ""));

	return 0;
}
