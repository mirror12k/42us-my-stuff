/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 10:30:30 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/26 13:11:01 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "ft_hexdump_print.h"

int		cmp_buffer(char *b1, char *b2, int count)
{
	while (count-- > 0)
		if (*b1++ != *b2++)
			return (0);
	return (1);
}

void	copy_buffer(char *dest, char *src, int count)
{
	while (count-- > 0)
		*dest++ = *src++;
}

void	hexdump_fd(int fd, int enable_text)
{
	char	buf[32];
	int		bytes_read;
	int		offset;
	int		repeated;

	repeated = 0;
	offset = 0;
	while ((bytes_read = read(fd, buf, 16)) > 0)
	{
		if (offset && bytes_read == 16 && cmp_buffer(buf + 16, buf, 16))
		{
			if (repeated == 0)
				write(1, "*\n", 2);
		}
		else
			print_buffer_line(offset, buf, bytes_read, enable_text);
		repeated = offset && bytes_read == 16 && cmp_buffer(buf + 16, buf, 16);
		copy_buffer(buf + 16, buf, 16);
		offset += bytes_read;
	}
	if (offset > 0)
	{
		print_addr(offset, enable_text);
		write(1, "\n", 1);
	}
}

void	hexdump_file(char *filepath, int enable_text)
{
	int fd;

	fd = open(filepath, O_RDONLY);
	hexdump_fd(fd, enable_text);
	close(fd);
}

int		main(int argc, char **argv)
{
	int i;
	int enable_text;

	enable_text = 0;
	i = 1;
	if (i < argc && cmp_buffer(argv[i], "-C", 3))
	{
		enable_text = 1;
		i++;
	}
	while (i < argc)
		hexdump_file(argv[i++], enable_text);
}
