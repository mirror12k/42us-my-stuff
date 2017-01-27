/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:34:31 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/16 09:50:57 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *search_str;
	char *found_str;
	char *find_str;

	search_str = str;
	found_str = str;
	find_str = to_find;
	if (*search_str == 0 && *find_str != 0)
		return (0);
	while (*find_str != 0)
		if (*find_str == *search_str)
		{
			find_str++;
			search_str++;
		}
		else
		{
			find_str = to_find;
			search_str = ++found_str;
			if (*search_str == 0)
				return (0);
		}
	return (found_str);
}
