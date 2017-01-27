

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split_whitespaces(char *str);

int main()
{
	for (char** res = ft_split_whitespaces("asdf qwerty  zxcv"); *res != 0; res++)
		printf("s: %s\n", *res);
	for (char** res = ft_split_whitespaces("\n \t\t  \n  "); *res != 0; res++)
		printf("s2: %s\n", *res);
	for (char** res = ft_split_whitespaces("      a        abc      xyz     "); *res != 0; res++)
		printf("s3: %s\n", *res);

	return 0;
}
