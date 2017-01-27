/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 09:29:37 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/18 20:04:49 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *range;
	int *iter;

	if (min >= max)
		return (0);
	range = malloc((max - min) * sizeof(int));
	if (range == 0)
		return (0);
	iter = range;
	while (min < max)
		*iter++ = min++;
	return (range);
}
