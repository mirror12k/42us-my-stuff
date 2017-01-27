/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 09:18:42 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/18 20:04:39 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	unsigned int	size;
	char			*str;

	size = 0;
	while (src[size++] != 0)
		;
	str = (char*)malloc(size);
	if (str == 0)
		return (0);
	size = 0;
	while (src[size] != 0)
	{
		str[size] = src[size];
		size++;
	}
	return (str);
}
