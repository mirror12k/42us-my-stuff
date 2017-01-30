/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 09:56:53 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/28 11:06:11 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int		my_atoi(char *str)
{
	int res;
	int sign;

	sign = (*str != '-') * 2 - 1;
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

void	my_putnbr(int n)
{
	if (n <= -10 || n >= 10)
		my_putnbr(n / 10);
	else if (n < 0)
		my_putchar('-');
	if (n < 0)
		my_putchar((-n) % 10 + '0');
	else
		my_putchar(n % 10 + '0');
}
