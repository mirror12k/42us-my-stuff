

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	ft_collatz_conjecture(unsigned int base);

int main()
{
	printf("7 -> %d\n", ft_collatz_conjecture(7));
	printf("27 -> %d\n", ft_collatz_conjecture(27));

	return 0;
}
