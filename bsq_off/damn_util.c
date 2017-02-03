/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damn_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhramut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:33:41 by akhramut          #+#    #+#             */
/*   Updated: 2017/02/01 14:23:31 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "damn_util.h"

#include <stdlib.h>

int				index_of_free(char *s, char c, int n)
{
	int			i;

	i = 0;
	while (i < n && s[i] != '\n' && s[i] != c)
		i++;
	return (i);
}

char			*my_realloc(char *data, int size, int new_size)
{
	char		*new_data;
	int			i;

	new_data = malloc(new_size);
	i = 0;
	while (i < size && i < new_size)
	{
		new_data[i] = data[i];
		i++;
	}
	free(data);
	return (new_data);
}

int				my_atoi(char *s)
{
	int res;

	res = 0;
	while (*s >= '0' && *s <= '9')
		res = res * 10 + *s++ - '0';
	return (res);
}
