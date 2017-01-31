/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:12:12 by exam              #+#    #+#             */
/*   Updated: 2017/01/20 20:23:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	my_putnstr(char *str, int n)
{
	write(1, str, n);
}

int		isspace(char c)
{
	return (c == ' ' || c == '\t');
}

void	skip_to_spaces(char **str)
{
	while (**str != 0 && !isspace(**str))
		str[0]++;
}

void	skip_to_not_spaces(char **str)
{
	while (**str != 0 && isspace(**str))
		str[0]++;
}

int		main(int argc, char **argv)
{
	char *last_word;
	char *iter;
	
	if (argc == 2)
	{
		last_word = 0;
		iter = argv[1];
		skip_to_not_spaces(&iter);
		while (*iter != 0)
		{
			last_word = iter;
			skip_to_spaces(&iter);
			skip_to_not_spaces(&iter);
		}
		if (last_word != 0)
		{
			iter = last_word;
			skip_to_spaces(&iter);
			write(1, last_word, iter - last_word);
		}
	}
	write(1, "\n", 1);
	return (0);
}
