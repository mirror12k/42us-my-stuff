/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:44:22 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/15 09:41:56 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_seq(int length, char c)
{
	while (length--)
		ft_putchar(c);
}

void	print_door_line(int width, int pad, int door_width, char door_handle)
{
	int i;

	i = width;
	pad -= width / 2;
	print_seq(pad, ' ');
	ft_putchar('/');
	if (door_width > 0)
	{
		print_seq((width - door_width) / 2, '*');
		if (door_width > 3)
		{
			print_seq(door_width - 2, '|');
			ft_putchar(door_handle);
			ft_putchar('|');
		}
		else
			print_seq(door_width, '|');
		print_seq((width - door_width) / 2, '*');
	}
	else
		print_seq(width, '*');
	ft_putchar('\\');
	ft_putchar('\n');
}

int		layer_width(int layer)
{
	int width;
	int i;

	width = 0;
	if (layer > 1)
	{
		width += layer_width(layer - 1);
		width += ((layer + 1) / 2) * 2;
	}
	i = 0;
	width += (layer + 3) * 2 - 1;
	return (width);
}

void	print_door_layer(int layer, int pad, int has_door)
{
	int width;
	int i;
	int door_height;
	int odd;

	door_height = layer + 2 - (3 - layer % 2);
	odd = 1 ^ (layer % 2);
	width = layer_width(layer) + odd;
	i = layer + 2;
	while (i > 0)
		if (has_door && i <= door_height && i == door_height / 2 + 1)
			print_door_line(width - i-- * 2, pad, layer - odd, '$');
		else if (has_door && i <= door_height)
			print_door_line(width - i-- * 2, pad, layer - odd, '|');
		else
			print_door_line(width - i-- * 2, pad, 0, '?');
}

void	sastantua(int size)
{
	int i;
	int pad;

	if (size > 0)
	{
		pad = layer_width(size) / 2 - 1;
		i = 0;
		while (i < size - 1)
			print_door_layer(++i, pad, 0);
		print_door_layer(++i, pad, 1);
	}
}
