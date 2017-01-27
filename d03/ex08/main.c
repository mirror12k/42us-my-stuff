

#include <stdio.h>

int	ft_atoi(char *str);

int main()
{
	printf("result: %d (should be 10)\n", ft_atoi("10"));
	printf("result: %d (should be 123456)\n", ft_atoi("123456"));
	printf("result: %d (should be -15)\n", ft_atoi("-15"));
	printf("result: %d (should be 0)\n", ft_atoi("0"));
	
	printf("result: %d (should be 2147483647)\n", ft_atoi("2147483647"));
	printf("result: %d (should be -2147483648)\n", ft_atoi("-2147483648"));

	return 0;
}
