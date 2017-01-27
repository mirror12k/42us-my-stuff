

#include <stdio.h>

int	ft_iterative_factorial(int nb);

int main()
{
	printf("!4: %d\n", ft_iterative_factorial(4));
	printf("!0: %d\n", ft_iterative_factorial(0));
	printf("!1: %d\n", ft_iterative_factorial(1));
	printf("!10: %d\n", ft_iterative_factorial(10));
	printf("!12: %d\n", ft_iterative_factorial(12));
	printf("!13: %d\n", ft_iterative_factorial(13));
	printf("!-2: %d\n", ft_iterative_factorial(-2));
	printf("!1000: %d\n", ft_iterative_factorial(1000));

	return 0;
}
