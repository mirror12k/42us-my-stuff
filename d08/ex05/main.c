

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ft_stock_par.h"

struct s_stock_par	*ft_param_to_tab(int ac, char **av);

int main(int argc, char** argv)
{
	struct s_stock_par* res;
	for(res = ft_param_to_tab(argc, argv); res->str != 0; res++)
	{
		printf("%d, %s, %s\n", res->size_param, res->str, res->copy);
		for (char** words = res->tab; *words != 0; words++)
			printf("\tword: '%s'\n", *words);

	}

	return 0;
}
