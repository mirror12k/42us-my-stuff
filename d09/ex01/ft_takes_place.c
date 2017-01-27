/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:45:04 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/19 19:03:41 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	my_format_time(int *hour, char *zone)
{
	if (*hour < 12)
		*zone = 'A';
	else
		*zone = 'P';
	*hour = *hour % 12;
	if (*hour == 0)
		*hour = 12;
}

void	ft_takes_place(int hour)
{
	int		start_time;
	int		end_time;
	char	start_zone;
	char	end_zone;

	start_time = hour % 24;
	end_time = (start_time + 1) % 24;
	my_format_time(&start_time, &start_zone);
	my_format_time(&end_time, &end_zone);
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00 %c.M. AND ", start_time, start_zone);
	printf("%d.00 %c.M.\n", end_time, end_zone);
}
