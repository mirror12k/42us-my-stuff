

#include <stdio.h>
#include <stdlib.h>

void	sastantua(int size);

int main(int argc, char** argv)
{
	int count = 0;
	if (argc > 1)
		count = atoi(argv[1]);
	
	sastantua(count);

	return 0;
}
