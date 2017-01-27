

#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int main()
{
	printf("asdf: %d\n", ft_str_is_lowercase("asdf"));
	printf("asdF: %d\n", ft_str_is_lowercase("asdF"));
	printf("aSdF: %d\n", ft_str_is_lowercase("aSdF"));
	printf("ASDF: %d\n", ft_str_is_lowercase("ASDF"));
	printf("asdf1: %d\n", ft_str_is_lowercase("asdf1"));
	printf("15: %d\n", ft_str_is_lowercase("15"));
	printf(": %d\n", ft_str_is_lowercase(""));

	return 0;
}
