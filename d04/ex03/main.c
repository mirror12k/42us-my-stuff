

#include <stdio.h>

int	ft_recursive_power(int nb, int power);

int main()
{
	printf("2^4: %d\n", ft_recursive_power(2, 4));
	printf("5^3: %d\n", ft_recursive_power(5, 3));
	printf("3^5: %d\n", ft_recursive_power(3, 5));
	printf("0^2: %d\n", ft_recursive_power(0, 2));
	printf("15^1: %d\n", ft_recursive_power(15, 1));
	printf("5^-4: %d\n", ft_recursive_power(5, -4));
	printf("5^-1: %d\n", ft_recursive_power(5, -1));
	printf("10^5: %d\n", ft_recursive_power(10, 5));

	return 0;
}
