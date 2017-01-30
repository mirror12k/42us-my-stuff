/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damn_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:48:53 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/28 15:55:54 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "damn_util.h"

char	*my_realloc(char *buffer, unsigned int size, unsigned int new_size)
{
	char			*res;
	unsigned int	i;

	res = malloc(new_size);
	i = 0;
	while (i < size)
	{
		res[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (res);
}

char	*get_input(void)
{
	int		bytes_read;
	char	*buffer;
	int		buffer_size;
	int		input_read;

	input_read = 0;
	buffer_size = 4096 * 4;
	buffer = malloc(4096 * 4);
	while ((bytes_read = read(0, buffer + input_read,
					buffer_size - input_read)) > 0)
	{
		input_read += bytes_read;
		if (input_read >= buffer_size)
		{
			buffer = my_realloc(buffer, buffer_size, buffer_size * 2);
			buffer_size *= 2;
		}
	}
	if (input_read == buffer_size)
	{
		buffer = my_realloc(buffer, buffer_size, buffer_size + 1);
		buffer_size++;
	}
	buffer[buffer_size - 1] = '\0';
	return (buffer);
}

int		my_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

void	my_putnbr(int n)
{
	char c;

	if (n <= -10 || n >= 10)
		my_putnbr(n / 10);
	else if (n < 0)
		write(1, "-", 1);
	if (n < 0)
		c = (-n) % 10 + '0';
	else
		c = n % 10 + '0';
	write(1, &c, 1);
}

void	print_trace(char *trace_name, t_dim dim, int first)
{
	if (!first)
		write(1, " || ", 4);
	write(1, "[", 1);
	write(1, trace_name, my_strlen(trace_name));
	write(1, "] [", 3);
	my_putnbr(dim.width);
	write(1, "] [", 3);
	my_putnbr(dim.height);
	write(1, "]", 1);
}
