

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_button(int i, int j, int k);

int main()
{
	printf("1,2,3 -> %d\n", ft_button(1,2,3));
	printf("3,2,1 -> %d\n", ft_button(3,2,1));
	printf("2,1,3 -> %d\n", ft_button(2,1,3));
	printf("2,3,1 -> %d\n", ft_button(2,3,1));
	printf("1,3,2 -> %d\n", ft_button(1,3,2));
	printf("3,1,2 -> %d\n", ft_button(3,1,2));

	return 0;
}
