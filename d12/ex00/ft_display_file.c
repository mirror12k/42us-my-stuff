/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:50:48 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/26 10:21:58 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	dump_file(char *filename)
{
	int		fd;
	int		bytes_read;
	char	buffer[4096 * 16];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read < 0)
		return (1);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read < 0)
			return (1);
	}
	if (close(fd) < 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else if (dump_file(argv[1]))
		write(1, "Error reading file.\n", 20);
	return (0);
}
