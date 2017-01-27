

#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int main()
{
	printf("0x28: %d\n", ft_atoi_base("28", "0123456789abcdef"));
	printf("0x0a: %d\n", ft_atoi_base("0a", "0123456789abcdef"));
	printf("0x10: %d\n", ft_atoi_base("10", "0123456789abcdef"));
	printf("0x1f: %d\n", ft_atoi_base("1f", "0123456789abcdef"));
	printf("0x1f: %d\n", ft_atoi_base("1f", "0123456789abcdef"));
	printf("-0x1f: %d\n", ft_atoi_base("-1f", "0123456789abcdef"));

	printf("1000: %d\n", ft_atoi_base("1000", "01"));
	printf("+1111: %d\n", ft_atoi_base("+1111", "01"));
	printf("-111: %d\n", ft_atoi_base("-111", "01"));
	
	return 0;
}
