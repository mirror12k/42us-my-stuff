/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:45:18 by exam              #+#    #+#             */
/*   Updated: 2017/01/20 20:56:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int v)
{
	int i;
	
	i = 2;
	while (i < v)
	{
		if (v % i == 0)
		{
			printf("%d*", i);
			v /= i;
			i = 2;
		}
		else
			i++;
	}
	if (i == v || v == 1)
		printf("%d", v);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
