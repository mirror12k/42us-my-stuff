/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:20:26 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/17 11:44:45 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int wrote;

	wrote = 0;
	if (size > 0)
	{
		while (src[wrote] != 0 && wrote < size - 1)
			*dest++ = src[wrote++];
		*dest = 0;
	}
	while (src[wrote] != 0)
		wrote++;
	return (wrote);
}
