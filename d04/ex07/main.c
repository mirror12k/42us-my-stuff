

#include <stdio.h>

int	ft_find_next_prime(int nb);

int main()
{
	printf("%d <- %d\n", ft_find_next_prime(2), 2);
	printf("%d <- %d\n", ft_find_next_prime(4), 4);
	printf("%d <- %d\n", ft_find_next_prime(5), 5);
	printf("%d <- %d\n", ft_find_next_prime(8), 8);
	printf("%d <- %d\n", ft_find_next_prime(16), 16);
	printf("%d <- %d\n", ft_find_next_prime(20), 20);

	return 0;
}
