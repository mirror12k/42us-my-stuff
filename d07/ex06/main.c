

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int main()
{
	printf("15 -> %s\n", ft_convert_base("15", "0123456789", "0123456789abcdef"));
	printf("1f -> %s\n", ft_convert_base("1f", "0123456789abcdef", "0123456789"));
	printf("-1000 -> %s\n", ft_convert_base("-1000", "0123456789abcdef", "0123456789"));
	printf("+01111 -> %s\n", ft_convert_base("+01111", "01", "0123456789"));
	printf("0 -> %s\n", ft_convert_base("0", "01", "0123456789"));

	return 0;
}
