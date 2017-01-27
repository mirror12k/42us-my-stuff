

#include <stdio.h>

char** ft_split_whitespaces(char* str);

int main()
{
	char** res;
	for (res = ft_split_whitespaces(" asdf qwert  \t\n zxcv\t\t"); *res != 0; res++)
		printf("%s\n", *res);
	return 0;
}
