

#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int main()
{
	ft_putnbr_base(15, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(-40, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(25, "0123456789");
	printf("\n");
	ft_putnbr_base('a', "01");
	printf("\n");
	ft_putnbr_base(-'a', "01");
	printf("\n");

	return 0;
}
