/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 09:50:59 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/18 20:05:13 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int		my_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

char				*ft_concat_params(int argc, char **argv)
{
	int		size;
	int		i;
	char	*iter;
	char	*buf;

	size = 0;
	i = 1;
	while (i < argc)
		size += my_strlen(argv[i++]) + 1;
	buf = malloc(size);
	if (buf == 0)
		return (0);
	size = 0;
	i = 1;
	while (i < argc)
	{
		iter = argv[i++];
		while (*iter != 0)
			buf[size++] = *iter++;
		buf[size++] = '\n';
	}
	buf[size - 1] = 0;
	return (buf);
}
