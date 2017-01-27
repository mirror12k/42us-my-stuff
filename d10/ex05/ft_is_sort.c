/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:02:32 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/23 19:53:10 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	while (length-- > 1)
		if (f(tab[0], tab[1]) > 0)
			return (0);
		else
			tab++;
	return (1);
}
