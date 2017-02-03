/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 18:48:24 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/02/01 11:19:13 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_map_descriptor {
	int		w;
	int		h;
	char	c_empty;
	char	c_obstacle;
	char	c_full;
	char	*data;
}				t_map;

typedef struct	s_square {
	int w;
	int x;
	int y;
}				t_square;

typedef struct	s_line_descriptor {
	int w;
	int d;
	char type;
}				t_line;

int		index_of_free(char *s, char c, int n)
{
	int i;

	i = 0;
	while (i < n && s[i] != '\n' && s[i] != c)
		i++;
	return (i);
}

int		is_valid_map(t_map map)
{
	int x;
	int y;
	char *pos;

	y = 0;
	while (y < map.h)
	{
		pos = map.data + y * (map.w + 1);
		x = 0;
		while (x < map.w)
		{
			if (pos[x] != map.c_empty &&
					pos[x] != map.c_obstacle)
				return (0);
			x++;
		}
		if (pos[x] != '\n')
			return (0);
		y++;
	}
	return (1);
}

void	mark_box(t_map map, t_square box)
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

void	output_map(t_map map)
{
	write(1, map.data, (map.w + 1) * map.h);
}

int		find_square(t_map map, int x, int y, t_square *bsq)
{
	int i;
	int f;
	int w;

	i = 0;
	w = bsq->w + 1;
	while (i < w)
	{
		f = index_of_free(map.data + x + (y + i) * (map.w + 1), map.c_obstacle, w);
		if (f < w)
			return (f + 1);
		i++;
	}
	bsq->x = x;
	bsq->y = y;
	bsq->w = w;
	return (0);
}

t_square	parse_bsq(t_map map)
{
	int		y;
	int		x;
	t_square bs;


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

t_map	parse_legend(char *data, int size)
{
	t_map desc;
	int i;

	desc.w = 0;
	i = 0;
	desc.h = atoi(data);
	while (data[i] >= '0' && data[i] <= '9')
		i++;
	desc.c_empty = data[i++];
	desc.c_obstacle = data[i++];
	desc.c_full = data[i++];
	if (data[i++] != '\n')
		return (desc);
	desc.data = data + i;
	desc.w = (size - i) / (desc.h) - 1;
	return (desc);
}

char	*my_realloc(char *data, int size, int new_size)
{
	char	*new_data;
	int		i;

	new_data = malloc(new_size);
	i = 0;
	while (i < size && i < new_size)
	{
		new_data[i] = data[i];
		i++;
	}
	return (new_data);
}

char	*read_fd(int fd, int *size)
{
	char *data;
	int bytes_read;
	int data_size;
	int data_offset;

	data_size = 20000 * 20000;
	data = malloc(data_size);
	data_offset = 0;
	while ((bytes_read = read(fd, data + data_offset, data_size - data_offset)) > 0)
	{
		data_offset += bytes_read;
		if (data_offset == data_size)
		{
			data = my_realloc(data, data_size, data_size * 2);
			data_size *= 2;
		}
	}
	*size = data_offset;
	return (data);
}

void	parse_fd(int fd)
{
	char *data;
	int size;
	
	data = read_fd(fd, &size);
	t_map map = parse_legend(data, size);
	t_square box;
	if (is_valid_map(map))
	{
		box = parse_bsq(map);
		mark_box(map, box);
		output_map(map);
	}
	else
		printf("map error\n");
}

void	parse_file(char *filename)
{
	int fd;
	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		parse_fd(fd);
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
			parse_file(argv[i++]);
	}
	else
		parse_fd(0);
	return (0);
}
