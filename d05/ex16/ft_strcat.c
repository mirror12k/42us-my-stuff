/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:31:32 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/16 13:04:32 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char *iter;

	iter = dest;
	while (*iter != 0)
		iter++;
	while (*src != 0)
		*iter++ = *src++;
	*iter = *src;
	return (dest);
}
