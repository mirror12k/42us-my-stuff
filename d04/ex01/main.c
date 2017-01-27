

#include <stdio.h>

int	ft_recursive_factorial(int nb);

int main()
{
	printf("4!: %d\n", ft_recursive_factorial(4));
	printf("1!: %d\n", ft_recursive_factorial(1));
	printf("0!: %d\n", ft_recursive_factorial(0));
	printf("12!: %d\n", ft_recursive_factorial(12));
	printf("13!: %d\n", ft_recursive_factorial(13));
	printf("1000!: %d\n", ft_recursive_factorial(1000));
	printf("-12!: %d\n", ft_recursive_factorial(-12));
	printf("10!: %d\n", ft_recursive_factorial(10));
	printf("-1000!: %d\n", ft_recursive_factorial(-1000));

	return 0;
}
