

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split(char *str, char *charset);

int main()
{
	for(char** res = ft_split("asdf qwerty zxcv", " "); *res != 0; res++)
		printf("s1: %s\n", *res);
	for(char** res = ft_split("a_+++_b+_+_+c", "_+"); *res != 0; res++)
		printf("s2: %s\n", *res);
	for(char** res = ft_split("nope", "nope"); *res != 0; res++)
		printf("s3: %s\n", *res);
	for(char** res = ft_split("___test+more+++___", "_+"); *res != 0; res++)
		printf("s4: %s\n", *res);

	return 0;
}
