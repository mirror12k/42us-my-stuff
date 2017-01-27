/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:34:55 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/21 18:39:58 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nmatch(char *s1, char *s2)
{
	int i;
	int matches;

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s2 == '*')
	{
		i = 0;
		matches = 0;
		while (s1[i] != '\0')
			matches += nmatch(s1 + i++, s2 + 1);
		matches += nmatch(s1 + i, s2 + 1);
		return (matches);
	}
	else if (*s1 == *s2)
		return (nmatch(s1 + 1, s2 + 1));
	else
		return (0);
}
