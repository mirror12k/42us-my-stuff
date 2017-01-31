/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:29:59 by exam              #+#    #+#             */
/*   Updated: 2017/01/20 20:42:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		isspace(char c)
{
	return (c == ' ' || c == '\t');
}

void	skip_to_non_spaces(char **str)
{
	while (**str != 0 && isspace(**str))
		str[0]++;
}

void	lowercase_until_spaced(char **str)
{
	while (**str != 0 && !isspace(**str))
	{
		if (**str >= 'A' && **str <= 'Z')
			**str |= 0x20;
		str[0]++;
	}
}

int		main(int argc, char **argv)
{
	char	*iter;

	if (argc < 2)
		write(1, "\n", 1);
	else
	{
		argv++;
		while (*argv != 0)
		{
			iter = *argv;
			skip_to_non_spaces(&iter);
			while (*iter != 0)
			{
				if (*iter >= 'a' && *iter <= 'z')
					*iter &= 0xdf;
				iter++;
				lowercase_until_spaced(&iter);
				skip_to_non_spaces(&iter);
			}
			write(1, *argv, iter - *argv);
			write(1, "\n", 1);
			argv++;
		}
	}
	return (0);
}
