/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 08:52:05 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/16 08:56:11 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	recursive_putnbr(int nb)
{
	if (nb > 9 || nb < -9)
		recursive_putnbr(nb / 10);
	if (nb < 0)
		ft_putchar(-(nb % 10) + '0');
	else
		ft_putchar(nb % 10 + '0');
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	recursive_putnbr(nb);
}
