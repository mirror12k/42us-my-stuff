/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:12:39 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/16 09:51:51 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char *cpydst;

	cpydst = dest;
	while (*src != 0)
		*cpydst++ = *src++;
	*cpydst = *src;
	return (dest);
}
