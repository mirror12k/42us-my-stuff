

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int main()
{
	printf("15: %d\n", ft_atoi("15"));
	printf("-25: %d\n", ft_atoi("-25"));
	printf("0: %d\n", ft_atoi("0"));

	printf("15a5: %d\n", ft_atoi("15a5"));
	printf("0x152: %d\n", ft_atoi("0x152"));
	printf("--25: %d\n", ft_atoi("--25"));
	
	printf("<spaces>+256: %d\n", ft_atoi(" \t\n\v\f\r+256"));
	
	return 0;
}
