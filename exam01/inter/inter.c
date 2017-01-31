/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:55:35 by exam              #+#    #+#             */
/*   Updated: 2017/01/20 20:06:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		my_putchar(char c)
{
	return (write(1, &c, 1));
}

int		my_indexof(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != 0)
		if (str[i] == c)
			return (i);
		else
			i++;
	return (-1);
}


int		main(int argc, char **argv)
{
	char *iter;
	char *search_iter;
	int	i;

	if (argc >= 3)
	{
		i = 0;
		while (argv[1][i] != 0)
		{
			if (my_indexof(argv[1], argv[1][i]) == i)
				if (my_indexof(argv[2], argv[1][i]) != -1)
					my_putchar(argv[1][i]);
			i++;
		}
	}
	my_putchar('\n');
	return (0);
}
