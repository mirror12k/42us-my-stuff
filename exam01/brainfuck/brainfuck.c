/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 21:17:16 by exam              #+#    #+#             */
/*   Updated: 2017/01/20 21:43:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void brainfuck_enter_scope(char **code, char v, char ***stack)
{
	int scope;

	if (v == 0)
	{
		scope = 1;
		while (scope > 0 && **code != 0)
		{
			code[0]++;
			if (**code == ']')
				scope--;
			else if (**code == '[')
				scope++;
		}
	}
	else
	{
		stack[0]++;
		**stack = *code;
	}
}

void brainfuck_exit_scope(char **code, char v, char ***stack)
{
	if (v == 0)
		stack[0]--;
	else
		*code = **stack;
}

void	brainfuck(char *code)
{
	char	data[2048];
	char	*p;
	char	*stack[1024];
	char	**stack_p;

	code--;
	p = data;
	stack_p = stack;
	while (*++code != 0)
		if (*code == '>')
			p++;
		else if (*code == '<')
			p--;
		else if (*code == '+')
			p[0]++;
		else if (*code == '-')
			p[0]--;
		else if (*code == '.')
			write(1, p, 1);
		else if (*code == '[')
			brainfuck_enter_scope(&code, *p, &stack_p);
		else if (*code == ']')
			brainfuck_exit_scope(&code, *p, &stack_p);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (1);
}
