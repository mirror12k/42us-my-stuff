#include "ft_boolean.h"

#include <stdio.h>

t_bool ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}
int main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		printf(EVEN_MSG);
	else
		printf(ODD_MSG);
	return (SUCCESS);
}

