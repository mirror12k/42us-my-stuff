/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 10:05:26 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/13 11:19:55 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int result;

	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0)
		return (1);
	result = 1;
	while (nb > 1)
		result *= nb--;
	return (result);
}
