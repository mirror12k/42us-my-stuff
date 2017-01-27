

#include <stdio.h>

int	ft_is_prime(int nb);

int main()
{
	printf("is_prime -5: %d\n", ft_is_prime(-5));
	printf("is_prime 0: %d\n", ft_is_prime(0));
	printf("is_prime 1: %d\n", ft_is_prime(1));
	printf("is_prime 2: %d\n", ft_is_prime(2));
	printf("is_prime 3: %d\n", ft_is_prime(3));
	printf("is_prime 4: %d\n", ft_is_prime(4));
	printf("is_prime 5: %d\n", ft_is_prime(5));
	printf("is_prime 10: %d\n", ft_is_prime(10));
	printf("is_prime 11: %d\n", ft_is_prime(11));
	printf("is_prime 13: %d\n", ft_is_prime(13));
	printf("is_prime 15: %d\n", ft_is_prime(15));
	printf("is_prime 17: %d\n", ft_is_prime(17));
	printf("is_prime 19: %d\n", ft_is_prime(19));
	printf("is_prime 21: %d\n", ft_is_prime(21));
	printf("is_prime 23: %d\n", ft_is_prime(23));
	printf("is_prime 2147395600: %d\n", ft_is_prime(2147395600));
	printf("is_prime 2147395601: %d\n", ft_is_prime(2147395601));

	return 0;
}
