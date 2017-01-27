

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_destroy(char ***factory);

int main()
{
	char*** factory = malloc(sizeof(char**) * 2);
	factory[1] = NULL;
	factory[0] = malloc(sizeof(char*) * 2);
	factory[0][1] = NULL;
	factory[0][0] = malloc(15);
	printf("debug: %x %x\n", (unsigned int)factory, (unsigned int)factory[0]);
	ft_destroy(factory);

	return 0;
}
