/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:21:50 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/17 09:30:08 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		main(int argc, char **argv)
{
	char *iter;

	if (argc > 0)
	{
		iter = argv[0];
		while (*iter != 0)
			ft_putchar(*iter++);
		ft_putchar('\n');
	}
	return (0);
}
