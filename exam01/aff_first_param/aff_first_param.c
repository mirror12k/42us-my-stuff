/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:24:02 by exam              #+#    #+#             */
/*   Updated: 2017/01/20 18:27:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		my_strlen(char* str)
{
	int len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
		write(1, argv[1], my_strlen(argv[1]));
	write(1, "\n", 1);
	return (0);
}
