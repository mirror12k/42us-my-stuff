/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:41:03 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/12 20:44:05 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	output_number_pair(int n1, int n2, int *first)
{
	if (n1 < n2)
	{
		if (*first)
			*first = 0;
		else
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		ft_putchar((n1 / 10) + '0');
		ft_putchar((n1 % 10) + '0');
		ft_putchar(' ');
		ft_putchar((n2 / 10) + '0');
		ft_putchar((n2 % 10) + '0');
	}
}

void	ft_print_comb2(void)
{
	int counter;
	int first;

	counter = -1;
	first = 1;
	while (counter++ < 10000)
		output_number_pair(counter / 100, counter % 100, &first);
}
