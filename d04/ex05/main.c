

#include <stdio.h>

int	ft_sqrt(int nb);

int main()
{
	printf("sqrt(-200): %d\n", ft_sqrt(-200));
	printf("sqrt(0): %d\n", ft_sqrt(0));
	printf("sqrt(1): %d\n", ft_sqrt(1));
	printf("sqrt(4): %d\n", ft_sqrt(4));
	printf("sqrt(5): %d\n", ft_sqrt(5));
	printf("sqrt(9): %d\n", ft_sqrt(9));
	printf("sqrt(36): %d\n", ft_sqrt(36));
	printf("sqrt(144): %d\n", ft_sqrt(144));
	printf("sqrt(64): %d\n", ft_sqrt(64));
	printf("sqrt(2147395600): %d\n", ft_sqrt(2147395600));

	return 0;
}
