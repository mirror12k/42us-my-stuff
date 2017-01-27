/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:14:14 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/14 14:34:37 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_square_greater(int nb)
{
	int i;

	i = 2;
	while (i <= 46340)
		if (i * i >= nb)
			return (i);
		else
			i++;
	return (46341);
}

int		is_prime(int nb)
{
	int i;
	int limit;

	if (nb % 2 == 0)
		return (0);
	limit = find_square_greater(nb);
	i = 3;
	while (i <= limit)
		if (nb % i == 0)
			return (0);
		else
			i += 2;
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (!is_prime(nb))
		nb += 2;
	return (nb);
}
