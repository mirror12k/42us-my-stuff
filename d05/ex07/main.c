

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
	printf("asdf $ asde (3): %d\n", ft_strncmp("asdf", "asde", 3));
	printf("asdf $ asdf (3): %d\n", ft_strncmp("asdf", "asdf", 3));
	printf("asdf $ asdg (3): %d\n", ft_strncmp("asdf", "asdg", 3));
	printf("asdf $ asde (15): %d\n", ft_strncmp("asdf", "asde", 15));
	printf("asdf $ asdf (15): %d\n", ft_strncmp("asdf", "asdf", 15));
	printf("asdf $ asdg (15): %d\n", ft_strncmp("asdf", "asdg", 15));


	printf("asdf $ asd (3): %d\n", ft_strncmp("asdf", "asd", 3));
	printf("asdf $ asd (4): %d\n", ft_strncmp("asdf", "asd", 4));
	printf("asd $ asdf (4): %d\n", ft_strncmp("asd", "asdf", 4));
	printf(" $ asdf (3): %d\n", ft_strncmp("", "asdf", 3));
	printf("asdf $ (3): %d\n", ft_strncmp("asdf", "", 3));
	printf(" $ (3): %d\n", ft_strncmp("", "", 3));

	return 0;
}
