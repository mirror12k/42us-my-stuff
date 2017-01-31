/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 19:18:12 by exam              #+#    #+#             */
/*   Updated: 2017/01/13 19:24:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main()
{
	char character;

	character = 'z';
	while (character >= 'a')
	{
		if (character % 2 == 1)
			character &= 0xDF;
		write(1, &character, 1);
		character |= 0x20;
		character--;
	}
	character = '\n';
	write(1, &character, 1);
	return (0);
}
