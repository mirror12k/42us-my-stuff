/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:44:58 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/17 11:30:17 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	my_puthex(unsigned char c)
{
	if ((c >> 4) > 9)
		ft_putchar((c >> 4) - 10 + 'a');
	else
		ft_putchar((c >> 4) + '0');
	if ((c & 0xf) > 9)
		ft_putchar((c & 0xf) - 10 + 'a');
	else
		ft_putchar((c & 0xf) + '0');
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != 0)
		if (*str > 0x1f && *str < 0x7f)
			ft_putchar(*str++);
		else
		{
			ft_putchar('\\');
			my_puthex(*str++);
		}
}
