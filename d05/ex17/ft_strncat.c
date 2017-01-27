/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:38:49 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/16 11:42:01 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	char *iter;

	iter = dest;
	while (*iter != 0)
		iter++;
	while (*src != 0 && nb-- != 0)
		*iter++ = *src++;
	*iter = 0;
	return (dest);
}
