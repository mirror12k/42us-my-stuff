/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 09:55:39 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/15 10:11:03 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	rush(int x, int y)
{
	int ix;
	int iy;

	iy = 0;
	while (iy < y)
	{
		ix = -1;
		while (++ix < x)
			if (iy == 0 && ix == 0)
				ft_putchar('/');
			else if (iy == 0 && ix == x - 1)
				ft_putchar('\\');
			else if (iy == y - 1 && ix == 0)
				ft_putchar('\\');
			else if (iy == y - 1 && ix == x - 1)
				ft_putchar('/');
			else if (iy == 0 || iy == y - 1)
				ft_putchar('*');
			else if (ix == 0 || ix == x - 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
		ft_putchar('\n');
		iy++;
	}
}
