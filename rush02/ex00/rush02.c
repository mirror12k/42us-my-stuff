/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:11:45 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/29 15:35:45 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "rush02.h"

int		get_trace_type(int x, int y, t_dim dim)
{
	if (x == 0 && y == 0)
		return (RUSH_TOP_LEFT);
	else if (x == dim.width - 1 && y == 0)
		return (RUSH_TOP_RIGHT);
	else if (x == 0 && y == dim.height - 1)
		return (RUSH_BOTTOM_LEFT);
	else if (x == dim.width - 1 && y == dim.height - 1)
		return (RUSH_BOTTOM_RIGHT);
	else if (y == 0 || y == dim.height - 1)
		return (RUSH_TOP_BOTTOM);
	else if (x == 0 || x == dim.width - 1)
		return (RUSH_LEFT_RIGHT);
	else
		return (RUSH_CENTER);
}

t_dim	get_dimensions(char *text)
{
	t_dim	dim;
	int		i;

	i = 0;
	dim.width = 0;
	dim.height = 0;
	while (*text != '\0')
	{
		if (*text == '\n')
		{
			if (i == 0 || (dim.width != 0 && dim.width != i))
			{
				dim.width = 0;
				return (dim);
			}
			else if (dim.width == 0)
				dim.width = i;
			i = 0;
			dim.height++;
		}
		else
			i++;
		text++;
	}
	return (dim);
}

int		trace_box(char *data, t_dim dim, char *trace)
{
	int i;

	i = 0;
	while (i < dim.height * dim.width)
	{
		if (data[i + i / dim.width] !=
				trace[get_trace_type(i % dim.width, i / dim.width, dim)])
			return (0);
		i++;
	}
	return (1);
}

static char	*g_traces[] = {"oooo-| ", "/\\\\/** ", "AACCBB ",
	"ACACBB ", "ACCABB "};
static char	*g_trace_names[] = {"rush-00", "rush-01", "rush-02",
	"rush-03", "rush-04"};

void	trace_rush(char *data, t_dim dim)
{
	unsigned int	index;
	int				first;

	first = 1;
	index = 0;
	while (index < sizeof(g_traces) / sizeof(char*))
	{
		if (trace_box(data, dim, g_traces[index]))
		{
			print_trace(g_trace_names[index], dim, first);
			first = 0;
		}
		index++;
	}
	if (first)
		write(1, "aucune", 6);
}

int		main(void)
{
	char	*buf;
	t_dim	dim;

	buf = get_input();
	dim = get_dimensions(buf);
	if (dim.width != 0)
		trace_rush(buf, dim);
	else
		write(1, "aucune", 6);
	write(1, "\n", 1);
	return (0);
}
