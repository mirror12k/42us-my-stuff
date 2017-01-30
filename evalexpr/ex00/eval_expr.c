/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 08:58:08 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/29 15:58:54 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "util.h"

int		parse_expression(char **exp, int sign);

char	parse_operator(char **exp)
{
	char op;

	op = '\0';
	while (**exp == ' ')
		exp[0]++;
	if (**exp == '+')
		op = **exp;
	if (**exp == '-')
		op = **exp;
	if (**exp == '*')
		op = **exp;
	if (**exp == '/')
		op = **exp;
	if (**exp == '%')
		op = **exp;
	if (op != '\0')
		exp[0]++;
	return (op);
}

int		parse_immediate(char **exp)
{
	int res;

	while (**exp == ' ')
		exp[0]++;
	if (**exp == '(')
	{
		exp[0]++;
		res = parse_expression(exp, 1);
		while (**exp == ' ')
			exp[0]++;
		exp[0]++;
	}
	else
	{
		res = my_atoi(*exp);
		if (**exp == '-' || **exp == '+')
			exp[0]++;
		while (**exp >= '0' && **exp <= '9')
			exp[0]++;
	}
	return (res);
}

int		parse_expression(char **exp, int sign)
{
	int		val;
	int		v2;
	char	op;

	val = sign * parse_immediate(exp);
	op = parse_operator(exp);
	while (op == '*' || op == '/' || op == '%')
	{
		v2 = parse_immediate(exp);
		if (op == '*')
			val *= v2;
		else if (op == '/')
			val /= v2;
		else
			val %= v2;
		op = parse_operator(exp);
	}
	if (op == '+')
		return (val + parse_expression(exp, 1));
	else if (op == '-')
		return (val + parse_expression(exp, -1));
	return (val);
}

int		eval_expr(char *exp)
{
	return (parse_expression(&exp, 1));
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		my_putnbr(eval_expr(argv[1]));
		write(1, "\n", 1);
	}
}
