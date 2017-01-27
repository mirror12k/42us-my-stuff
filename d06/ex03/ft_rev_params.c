/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:47:58 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/17 10:14:46 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	my_putstr(char *str)
{
	while (*str != 0)
		ft_putchar(*str++);
}

int		main(int argc, char **argv)
{
	int i;

	i = argc - 1;
	while (i > 0)
	{
		my_putstr(argv[i--]);
		ft_putchar('\n');
	}
	return (0);
}
