
#include <stdio.h>

#include "test.h"

int main(int argc, char **argv)
{
	for (int i = LOL; i < argc; i++)
		printf("lol hi: %s\n", argv[i]);
}

