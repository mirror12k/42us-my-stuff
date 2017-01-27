

#include <stdio.h>

int	ft_str_is_numeric(char *str);

int main()
{
	printf("15: %d\n", ft_str_is_numeric("15"));
	printf("asdf: %d\n", ft_str_is_numeric("asdf"));
	printf("15asdf: %d\n", ft_str_is_numeric("15asdf"));
	printf(": %d\n", ft_str_is_numeric(""));
	

	return 0;
}
