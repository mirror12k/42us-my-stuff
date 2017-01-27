/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 09:11:02 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/20 09:36:52 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		my_strcmpi(char *s1, char *s2)
{
	while (*s1 != 0 && *s2 != 0)
		if ((*s1 | 0x20) != (*s2 | 0x20))
			return (1);
		else
		{
			s1++;
			s2++;
		}
	if (*s1 != 0 || *s2 != 0)
		return (1);
	return (0);
}

int		eyespy(char *str)
{
	if (my_strcmpi(str, "president") == 0)
		return (1);
	else if (my_strcmpi(str, "attack") == 0)
		return (1);
	else if (my_strcmpi(str, "powers") == 0)
		return (1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int flag;

	flag = 0;
	argv++;
	if (argc < 2)
		return (0);
	while (*argv != 0)
		flag += eyespy(*argv++);
	if (flag)
		write(1, "Alert!!!\n", 9);
	return (0);
}
