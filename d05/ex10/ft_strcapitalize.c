/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:33:08 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/16 19:12:34 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alphanumeric(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char *iter;

	iter = str;
	while (*iter != 0)
		if (is_alphanumeric(*iter))
		{
			if (*iter >= 'a' && *iter <= 'z')
				*iter &= 0xdf;
			iter++;
			while (is_alphanumeric(*iter))
				if (*iter >= 'A' && *iter <= 'Z')
					*iter++ |= 0x20;
				else
					iter++;
		}
		else
			iter++;
	return (str);
}
