

#include <stdio.h>

int	ft_fibonacci(int index);

int main()
{
	printf("fib(0): %d\n", ft_fibonacci(0));
	printf("fib(1): %d\n", ft_fibonacci(1));
	printf("fib(2): %d\n", ft_fibonacci(2));
	printf("fib(3): %d\n", ft_fibonacci(3));
	printf("fib(4): %d\n", ft_fibonacci(4));
	printf("fib(5): %d\n", ft_fibonacci(5));
	printf("fib(6): %d\n", ft_fibonacci(6));
	printf("fib(-1): %d\n", ft_fibonacci(-1));

	return 0;
}
