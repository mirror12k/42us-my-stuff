/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 19:28:44 by exam              #+#    #+#             */
/*   Updated: 2017/01/13 19:36:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char *str_fwd;
	char *str_rev;
	char swap;

	str_fwd = str;
	str_rev = str;
	while (*str_rev != 0)
		str_rev++;
	str_rev--;
	while (str_fwd < str_rev)
	{
		swap = *str_fwd;
		*str_fwd++ = *str_rev;
		*str_rev-- = swap;
	}
	return str;
}
