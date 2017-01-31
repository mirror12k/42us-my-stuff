/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:59:59 by exam              #+#    #+#             */
/*   Updated: 2017/01/20 21:10:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	unsigned int	i;
	int				size;
	char			*res;

	if (base == 10 && value < 0)
		i = -value;
	else
		i = value;
	size = 1 + (base == 10 && value < 0);
	while ((i /= base) != 0)
		size++;
	res = malloc(size + 1);
	res[size] = '\0';
	if (base == 10 && value < 0)
		i = -value;
	else
		i = value;
	res[--size] = "0123456789ABCDEF"[i % base];
	while ((i /= base) != 0)
		res[--size] = "0123456789ABCDEF"[i % base];
	if (base == 10 && value < 0)
		res[--size] = '-';
	return (res);
}
