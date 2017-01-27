/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:23:39 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/19 11:48:59 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

char				**ft_split_whitespaces(char *str);

int					my_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

char				*my_strdup(char *str)
{
	char *res;
	char *iter;

	res = malloc(my_strlen(str) + 1);
	iter = res;
	while (*str != 0)
		*iter++ = *str++;
	*iter = '\0';
	return (res);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par *res;
	struct s_stock_par *iter;

	res = malloc(sizeof(struct s_stock_par) * ac + 1);
	iter = res;
	while (*av != 0)
	{
		iter->str = *av;
		iter->size_param = my_strlen(*av);
		iter->copy = my_strdup(*av);
		iter->tab = ft_split_whitespaces(*av);
		av++;
		iter++;
	}
	iter->str = 0;
	return (res);
}
