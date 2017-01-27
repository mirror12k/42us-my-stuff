/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:41:36 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/12 20:44:16 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_number(int n)
{
	if (n >= 0)
		ft_putchar(n + '0');
	else
		ft_putchar(-n + '0');
}

void	recursive_print_number(int nb)
{
	if ((nb > -10) && (nb < 10))
	{
		print_number(nb % 10);
	}
	else
	{
		recursive_print_number(nb / 10);
		print_number(nb % 10);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else
	{
		if (nb < 0)
			ft_putchar('-');
		recursive_print_number(nb);
	}
}
