/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:57:48 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/26 10:21:02 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	cat_fd(int fd)
{
	int		bytes_read;
	char	buffer[4096 * 4];

	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
}

void	cat_file(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	cat_fd(fd);
	close(fd);
}

int		my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != 0)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc < 2)
		cat_fd(1);
	else
	{
		i = 0;
		while (++i < argc)
			if (my_strcmp(argv[i], "-") == 0)
				cat_fd(1);
			else if (my_strcmp(argv[i], "--") == 0)
				cat_fd(1);
			else
				cat_file(argv[i]);
	}
	return (0);
}
