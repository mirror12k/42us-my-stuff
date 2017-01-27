/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:40:21 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/18 11:42:59 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	my_putstr(char *s)
{
	while (*s != 0)
		ft_putchar(*s++);
}

void	ft_print_words_tables(char **tab)
{
	while (*tab != 0)
	{
		my_putstr(*tab++);
		ft_putchar('\n');
	}
}
