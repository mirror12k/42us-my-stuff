/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:01:05 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/18 20:06:02 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		my_in_charset(char c, char *charset)
{
	while (*charset != '\0')
		if (*charset++ == c)
			return (1);
	return (0);
}

int		my_skip_to_non_charset(char **str, char *charset)
{
	int i;

	i = 0;
	while (my_in_charset(str[0][i], charset))
		i++;
	*str += i;
	return (i);
}

int		my_skip_to_charset(char **str, char *charset)
{
	int i;

	i = 0;
	while (str[0][i] != 0 && !my_in_charset(str[0][i], charset))
		i++;
	*str += i;
	return (i);
}

char	*my_tear_string(char *str, char *charset)
{
	char *str_iter;
	char *res;
	char *res_iter;

	str_iter = str;
	my_skip_to_charset(&str, charset);
	res = (char*)malloc(1 + str - str_iter);
	res_iter = res;
	while (str_iter < str)
		*res_iter++ = *str_iter++;
	*res_iter = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	*iter;
	char	**res;
	char	**next_res;

	my_skip_to_non_charset(&str, charset);
	iter = str;
	size = 1;
	while (*iter != 0)
	{
		if (my_skip_to_charset(&iter, charset) > 0)
			size++;
		my_skip_to_non_charset(&iter, charset);
	}
	res = (char**)malloc(sizeof(char*) * size);
	next_res = res;
	iter = str;
	while (*iter != 0)
	{
		*next_res++ = my_tear_string(iter, charset);
		my_skip_to_charset(&iter, charset);
		my_skip_to_non_charset(&iter, charset);
	}
	*next_res = 0;
	return (res);
}
