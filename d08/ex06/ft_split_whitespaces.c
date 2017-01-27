/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:20:46 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/18 20:29:00 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		my_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		my_spaced_strlen(char *str)
{
	int len;

	len = 0;
	while (*str != 0 && !my_isspace(*str))
	{
		len++;
		str++;
	}
	return (len);
}

char	*my_strndup(char *source, int n)
{
	char	*res;
	int		i;

	res = malloc(n + 1);
	if (res == 0)
		return (0);
	i = 0;
	while (i < n)
		res[i++] = *source++;
	res[i] = 0;
	return (res);
}

char	**ft_split_whitespaces(char *str)
{
	char	**res;
	int		i;
	char	*iter;
	char	**dest;

	i = 0;
	iter = str;
	while (*iter != 0)
	{
		i += 0 != my_spaced_strlen(iter);
		iter += my_spaced_strlen(iter);
		iter += *iter != 0;
	}
	res = malloc((i + 1) * sizeof(char*));
	iter = str;
	dest = res;
	while (*iter != 0)
	{
		if (my_spaced_strlen(iter) > 0)
			*dest++ = my_strndup(iter, my_spaced_strlen(iter));
		iter += my_spaced_strlen(iter);
		iter += *iter != 0;
	}
	*dest = 0;
	return (res);
}
