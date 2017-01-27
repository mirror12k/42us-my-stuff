

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_concat_params(int argc, char **argv);

int main(int argc, char** argv)
{
	char* res = ft_concat_params(argc, argv);
	printf("res: %s", res);
	return 0;
}
