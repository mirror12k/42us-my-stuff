/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:46:35 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/17 10:47:27 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int wrote;
	unsigned int overflow;

	i = 0;
	while (dest[i] != 0 && i < size)
		i++;
	wrote = 0;
	if (size > 0 && dest[i] == 0)
	{
		while (src[wrote] != 0 && i < size - 1)
			dest[i++] = src[wrote++];
		dest[i] = 0;
	}
	overflow = 0;
	while (src[wrote++] != 0)
		overflow++;
	return (i + overflow);
}
