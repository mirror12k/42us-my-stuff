

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int main()
{
	printf("asdf $ sd: %s\n", ft_strstr("asdf", "sd"));
	printf("qwerqwerqwer $ rq: %s\n", ft_strstr("qwerqwerqwer", "rq"));
	printf("qwer $ asdf: %s\n", ft_strstr("qwer", "asdf"));
	printf("asdf $ asdff: %s\n", ft_strstr("asdf", "asdff"));
	printf(" $ affff: %s\n", ft_strstr("", "affff"));
	printf("asdf $ : %s\n", ft_strstr("asdf", ""));

	return 0;
}
