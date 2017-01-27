

#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int main()
{
	printf("asdf: %d\n", ft_str_is_uppercase("asdf"));
	printf("asdfASDF: %d\n", ft_str_is_uppercase("asdfASDF"));
	printf("asDF: %d\n", ft_str_is_uppercase("asDF"));
	printf("ASDf: %d\n", ft_str_is_uppercase("aSDf"));
	printf("ASDF: %d\n", ft_str_is_uppercase("ASDF"));
	printf("15: %d\n", ft_str_is_uppercase("15"));
	printf(": %d\n", ft_str_is_uppercase(""));

	return 0;
}
