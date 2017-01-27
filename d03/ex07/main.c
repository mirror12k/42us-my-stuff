

#include <stdio.h>

char*	ft_strrev(char *str);

int main()
{
	char teststr[] = "abcde";
	printf("abcde: %s\n", ft_strrev(teststr));
	char teststr2[] = "abcd";
	printf("abcd: %s\n", ft_strrev(teststr2));

	return 0;
}
