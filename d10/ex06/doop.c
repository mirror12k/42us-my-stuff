/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:12:41 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/23 15:38:40 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "doop_ops.h"

int		my_atoi(char *str)
{
	int res;
	int sign;

	sign = (*str == '-') * -2 + 1;
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

int		my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

t_op	get_operator(char *op)
{
	if (op[0] == '+' && op[1] == 0)
		return (my_op_add);
	else if (op[0] == '-' && op[1] == 0)
		return (my_op_subtract);
	else if (op[0] == '*' && op[1] == 0)
		return (my_op_multiply);
	else if (op[0] == '/' && op[1] == 0)
		return (my_op_divide);
	else if (op[0] == '%' && op[1] == 0)
		return (my_op_modulo);
	else
		return (0);
}

void	my_putnbr(int n)
{
	char c;

	if (n < -9 || n > 9)
		my_putnbr(n / 10);
	else if (n < 0)
		write(1, "-", 1);
	if (n < 0)
		c = -n % 10 + '0';
	else
		c = n % 10 + '0';
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	t_op	op;
	int		v1;
	int		v2;
	int		res;

	if (argc >= 4)
	{
		v1 = my_atoi(argv[1]);
		v2 = my_atoi(argv[3]);
		op = get_operator(argv[2]);
		res = 0;
		if (op == my_op_divide && v2 == 0)
			write(1, "Stop : division by zero", 23);
		else if (op == my_op_modulo && v2 == 0)
			write(1, "Stop : modulo by zero", 21);
		else if (op != 0)
		{
			res = op(v1, v2);
			my_putnbr(res);
		}
		else
			my_putnbr(0);
		write(1, "\n", 1);
	}
	return (0);
}
