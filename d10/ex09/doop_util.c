/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:54:21 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/23 14:58:57 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	while (*s1 == *s2 && *s1 != 0)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
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

int		my_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++ != 0)
		i++;
	return (i);
}
