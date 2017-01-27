

#include <stdio.h>

int	ft_str_is_printable(char *str);

int main()
{
	printf("asdf: %d\n", ft_str_is_printable("asdf"));
	printf("asdf15: %d\n", ft_str_is_printable("asdf15"));
	printf("asdf qwerty: %d\n", ft_str_is_printable("asdf qwerty"));
	printf(": %d\n", ft_str_is_printable(""));
	printf("!@#$%%^&*(): %d\n", ft_str_is_printable("!@#$%%^&*()"));
	printf("\\x01: %d\n", ft_str_is_printable("\x01"));
	printf("\\n: %d\n", ft_str_is_printable("\n"));
	printf("\\x7f: %d\n", ft_str_is_printable("\x7f"));
	printf("\\x81: %d\n", ft_str_is_printable("\x81"));
	printf("\\x1f: %d\n", ft_str_is_printable("\x1f"));

	return 0;
}
