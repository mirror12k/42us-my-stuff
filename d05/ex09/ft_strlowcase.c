/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:26:10 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/16 10:27:04 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char *iter;

	iter = str;
	while (*iter != 0)
		if (*iter >= 'A' && *iter <= 'Z')
			*iter++ |= 0x20;
		else
			iter++;
	return (str);
}
