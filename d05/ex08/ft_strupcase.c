/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:16:15 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/16 11:00:47 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char *iter;

	iter = str;
	while (*iter != 0)
		if (*iter >= 'a' && *iter <= 'z')
			*iter++ &= 0xdf;
		else
			iter++;
	return (str);
}
