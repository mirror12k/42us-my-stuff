/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 23:05:44 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/13 23:07:57 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char *str_front;
	char *str_back;
	char swap;

	str_front = str;
	str_back = str;
	while (*str_back != 0)
		str_back++;
	str_back--;
	while (str_front < str_back)
	{
		swap = *str_front;
		*str_front++ = *str_back;
		*str_back-- = swap;
	}
	return (str);
}
