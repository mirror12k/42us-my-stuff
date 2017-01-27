

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_takes_place(int hour);

int main(int argc, char** argv)
{
	if (argc < 2)
		return 1;
	int v = atoi(argv[1]);
	ft_takes_place(v);

	return 0;
}
