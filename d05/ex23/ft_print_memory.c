/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:14:08 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/16 15:50:11 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_hex(unsigned char c)
{
	if ((c >> 4) > 9)
		ft_putchar((c >> 4) - 10 + 'a');
	else
		ft_putchar((c >> 4) + '0');
	if ((c & 0xf) > 9)
		ft_putchar((c & 0xf) - 10 + 'a');
	else
		ft_putchar((c & 0xf) + '0');
}

void	print_addr(unsigned int offset)
{
	print_hex((offset >> 24) & 0xff);
	print_hex((offset >> 16) & 0xff);
	print_hex((offset >> 8) & 0xff);
	print_hex(offset & 0xff);
	ft_putchar(':');
	ft_putchar(' ');
}

void	print_data(char *addr, unsigned int count)
{
	unsigned int i;

	i = 0;
	while (i < 16)
	{
		if (i >= count)
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		else
			print_hex(addr[i]);
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	print_text(char *addr, unsigned int count)
{
	unsigned int i;

	i = 0;
	while (i < 16 && i < count)
	{
		if (addr[i] > 0x1f && addr[i] < 0x7f)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int offset;

	offset = 0;
	while (offset < size)
	{
		print_addr(offset);
		print_data((char*)addr + offset, size - offset);
		print_text((char*)addr + offset, size - offset);
		offset += 0x10;
		ft_putchar('\n');
	}
	return (addr);
}
