/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhramut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:53:43 by akhramut          #+#    #+#             */
/*   Updated: 2017/02/01 19:15:54 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void			output_map(t_map map)
{
	write(1, map.data, (map.w + 1) * map.h);
}

char			*read_fd(int fd, int *size)
{
	char		*data;
	int			bytes_read;
	int			data_size;
	int			offset;

	data_size = 20000 * 20000;
	data = malloc(data_size);
	offset = 0;
	while ((bytes_read = read(fd,
					data + offset, data_size - offset)) > 0)
	{
		offset += bytes_read;
		if (offset == data_size)
		{
			data = my_realloc(data, data_size, data_size * 2);
			data_size *= 2;
		}
	}
	*size = offset;
	return (data);
}

void			parse_fd(int fd)
{
	char		*data;
	int			size;
	t_square	box;
	t_map		map;

	data = read_fd(fd, &size);
	map = parse_legend(data, size);
	if (is_valid_map(map))
	{
		box = parse_bsq(map);
		mark_box(map, box);
		output_map(map);
	}
	else
		write(2, "map error\n", 10);
	free(data);
}

void			parse_file(char *filename)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		parse_fd(fd);
		close(fd);
	}
}

int				main(int argc, char **argv)
{
	int			i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			parse_file(argv[i]);
			++i;
		}
	}
	else
		parse_fd(0);
	return (0);
}
