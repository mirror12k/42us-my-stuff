/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhramut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:48:58 by akhramut          #+#    #+#             */
/*   Updated: 2017/02/01 19:26:12 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "damn_util.h"
#include "map_stuff.h"

t_map			parse_legend(char *data, int size)
{
	t_map		desc;
	int			i;

	desc.w = 0;
	i = 0;
	desc.h = my_atoi(data);
	while (data[i] >= '0' && data[i] <= '9')
		i++;
	desc.c_empty = data[i++];
	desc.c_obstacle = data[i++];
	desc.c_full = data[i++];
	if (data[i++] != '\n')
		return (desc);
	desc.data = data + i;
	if ((size - i) % desc.h)
		return (desc);
	desc.w = (size - i) / (desc.h) - 1;
	return (desc);
}

int				is_valid_map(t_map map)
{
	int			x;
	int			y;
	char		*pos;

	if (map.c_empty == map.c_obstacle || map.c_obstacle == map.c_full
			|| map.c_full == map.c_empty)
		return (0);
	y = 0;
	while (y < map.h)
	{
		pos = map.data + y * (map.w + 1);
		x = 0;
		while (x < map.w)
			if (pos[x] != map.c_empty && pos[x] != map.c_obstacle)
				return (0);
			else
				x++;
		if (pos[x] != '\n')
			return (0);
		y++;
	}
	return (1);
}

void			mark_box(t_map map, t_square box)
{
	int x;
	int y;

	y = 0;
	while (y < box.w)
	{
		x = 0;
		while (x < box.w)
		{
			map.data[(y + box.y) * (map.w + 1) + box.x + x] = map.c_full;
			x++;
		}
		y++;
	}
}

int				find_square(t_map map, int x, int y, t_square *bsq)
{
	int			i;
	int			f;
	int			w;

	i = 0;
	w = bsq->w + 1;
	while (i < w)
	{
		f = index_of_free(map.data + x + (y + i) *
				(map.w + 1), map.c_obstacle, w);
		if (f < w)
			return (f + 1);
		i++;
	}
	bsq->x = x;
	bsq->y = y;
	bsq->w = w;
	return (0);
}

t_square		parse_bsq(t_map map)
{
	int			y;
	int			x;
	t_square	bs;

	bs.w = 0;
	bs.x = 0;
	bs.y = 0;
	y = 0;
	while (y < map.h - bs.w)
	{
		x = 0;
		while (x < map.w - bs.w && y < map.h - bs.w)
			x += find_square(map, x, y, &bs);
		y++;
	}
	return (bs);
}
