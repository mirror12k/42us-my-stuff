/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:53:14 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/21 18:12:35 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	match(char *s1, char *s2)
{
	int i;

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s2 == '*')
	{
		i = 0;
		while (s1[i] != '\0')
			if (match(s1 + i, s2 + 1))
				return (1);
			else
				i++;
		if (match(s1 + i, s2 + 1))
			return (1);
		return (0);
	}
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else
		return (0);
}
