/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:12:41 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/23 15:50:00 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "doop.h"

t_op	get_operator(char *op)
{
	unsigned long i;

	i = 0;
	while (i < sizeof(g_opptab) / sizeof(t_opp))
	{
		if (my_strcmp(op, g_opptab[i].key) == 0)
			return (g_opptab[i].fun);
		i++;
	}
	return (get_operator(""));
}

int		ft_usage(int a, int b)
{
	unsigned long i;

	a += b;
	write(1, "error : only [ ", 15);
	i = 0;
	while (i < sizeof(g_opptab) / sizeof(t_opp))
	{
		if (my_strcmp("", g_opptab[i].key) != 0)
		{
			write(1, g_opptab[i].key, my_strlen(g_opptab[i].key));
			write(1, " ", 1);
		}
		i++;
	}
	write(1, "] are accepted.", 15);
	return (0);
}

int		main(int argc, char **argv)
{
	t_op	op;
	int		v1;
	int		v2;
	int		res;

	if (argc < 4)
		return (0);
	v1 = my_atoi(argv[1]);
	v2 = my_atoi(argv[3]);
	op = get_operator(argv[2]);
	res = 0;
	if (op == ft_div && v2 == 0)
		write(1, "Stop : division by zero", 23);
	else if (op == ft_mod && v2 == 0)
		write(1, "Stop : modulo by zero", 21);
	else if (op != 0)
	{
		res = op(v1, v2);
		if (op != ft_usage)
			my_putnbr(res);
	}
	else
		my_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
