

#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int main()
{
	char test[] = "asdf\nthis is a test string which is pretty awesome!!!";
	ft_print_memory(test, 0x4f);

	return 0;
}
