
#include <unistd.h>

int		ft_putchar(char c);

void	*malloc(unsigned long size);

int ft_putchar(char c)
{
	return write(STDOUT_FILENO, &c, 1);
}

