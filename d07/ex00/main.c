

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src);

int main()
{
	char* test = "asdf";
	char* res = ft_strdup(test);
	printf("%x vs %x\n", (unsigned int)test, (unsigned int)res);
	printf("%s\n", res);

	return 0;
}
