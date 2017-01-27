/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:40:28 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/12 21:04:59 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb(void)
{
	int n;
	int found;

	n = -1;
	found = 0;
	while (++n < 1000)
		if ((n / 100 < n % 100 / 10) && (n % 100 / 10 < n % 10))
		{
			if (found++ != 0)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_putchar((n / 100) + '0');
			ft_putchar((n % 100 / 10) + '0');
			ft_putchar((n % 10) + '0');
		}
}
