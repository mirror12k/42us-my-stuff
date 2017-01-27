

#include <stdio.h>

int	ft_str_is_alpha(char *str);

int main()
{
	printf("asdf: %d\n", ft_str_is_alpha("asdf"));
	printf("asdf1: %d\n", ft_str_is_alpha("asdf1"));
	printf("15: %d\n", ft_str_is_alpha("15"));
	printf(": %d\n", ft_str_is_alpha(""));

	return 0;
}
