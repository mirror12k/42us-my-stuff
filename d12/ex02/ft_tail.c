/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:39:49 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/26 10:13:37 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	head(int bytes, char *filename)
{
	char	buf[4096 * 4];
	char	*dev_null;
	int		bytes_read;
	int		fd;

	fd = open(filename, O_RDONLY);
	dev_null = malloc(bytes);
	read(fd, dev_null, bytes);
	while ((bytes_read = read(fd, buf, sizeof(buf))) > 0)
		write(1, buf, bytes_read);
	close(fd);
}

void	tail(int bytes, char *filename)
{
	char	*block1;
	char	*block2;
	int		bytes_read;
	int		fd;

	fd = open(filename, O_RDONLY);
	block1 = malloc(bytes);
	bytes_read = read(fd, block1, bytes);
	if (bytes_read < bytes)
		write(1, block1, bytes_read);
	else
	{
		block2 = malloc(bytes);
		while ((bytes_read = read(fd, block2, bytes)) == bytes)
		{
			free(block1);
			block1 = block2;
			block2 = malloc(bytes);
		}
		write(1, block1 + bytes_read, bytes - bytes_read);
		write(1, block2, bytes_read);
		free(block2);
	}
	free(block1);
	close(fd);
}

int		my_atoi(char *str)
{
	int res;
	int sign;

	res = 0;
	sign = (*str == '+') * 2 - 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

int		main(int argc, char **argv)
{
	int i;
	int bytes;

	if (argc < 3)
		return (1);
	else
	{
		bytes = my_atoi(argv[2]);
		i = 3;
		while (i < argc)
			if (bytes < 0)
				tail(-bytes, argv[i++]);
			else
				head(bytes - 1, argv[i++]);
	}
	return (0);
}
