/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:22:50 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/16 09:52:00 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *dstcpy;

	dstcpy = dest;
	while (n--)
		if (*src == 0)
			*dstcpy++ = 0;
		else
			*dstcpy++ = *src++;
	return (dest);
}
