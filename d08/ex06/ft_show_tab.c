/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:32:45 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/19 17:16:35 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int		ft_putchar(char c);

void	my_putstr(char *str)
{
	while (*str != 0)
		ft_putchar(*str++);
}

void	my_putnbr(unsigned int n)
{
	if (n >= 10)
		my_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_show_tab(struct s_stock_par *par)
{
	char **words;

	while (par->str != 0)
	{
		my_putstr(par->str);
		ft_putchar('\n');
		my_putnbr(par->size_param);
		ft_putchar('\n');
		words = par->tab;
		while (*words != 0)
		{
			my_putstr(*words++);
			ft_putchar('\n');
		}
		par++;
	}
}
