

#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int main()
{
	ft_putstr_non_printable("hello world!\n\x7f\xff");

	return 0;
}
