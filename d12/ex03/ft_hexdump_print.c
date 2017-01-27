/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:30:56 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/26 13:06:00 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char c, int count)
{
	char out;

	if (count == 2)
	{
		if ((c >> 4) >= 0xa)
			out = (c >> 4) - 0xa + 'a';
		else
			out = (c >> 4) + '0';
		write(1, &out, 1);
	}
	if ((c & 0xf) >= 0xa)
		out = (c & 0xf) - 0xa + 'a';
	else
		out = (c & 0xf) + '0';
	write(1, &out, 1);
}

void	print_addr(unsigned int addr, int enable_text)
{
	if (enable_text)
		print_hex((addr >> 24) & 0xff, 2);
	else
		print_hex((addr >> 24) & 0xff, 1);
	print_hex((addr >> 16) & 0xff, 2);
	print_hex((addr >> 8) & 0xff, 2);
	print_hex(addr & 0xff, 2);
}

void	print_data(char *data, int limit, int enable_break)
{
	int i;

	i = 0;
	while (i < 16)
	{
		write(1, " ", 1);
		if (enable_break && i == 8)
			write(1, " ", 1);
		if (i < limit)
			print_hex(data[i], 2);
		else
			write(1, "  ", 2);
		i++;
	}
}

void	print_text(char *data, int limit)
{
	int i;

	i = 0;
	write(1, "  |", 3);
	while (i < limit)
	{
		if (data[i] >= 0x20 && data[i] <= 0x7e)
			write(1, data + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
}

void	print_buffer_line(int offset, char *buffer, int bytes, int enable_text)
{
	print_addr(offset, enable_text);
	if (enable_text)
		write(1, " ", 1);
	print_data(buffer, bytes, enable_text);
	if (enable_text)
		print_text(buffer, bytes);
	write(1, "\n", 1);
}
