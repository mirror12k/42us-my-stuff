/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:09:02 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/17 20:21:18 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		parse_base(char *base)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (base[size] != 0)
	{
		if (base[size] == '+' || base[size] == '-')
			return (-1);
		i = 0;
		while (base[i] != 0)
			if (base[i] == base[size] && i != size)
				return (-1);
			else
				i++;
		size++;
	}
	if (size < 2)
		return (-1);
	return (size);
}

int		ft_atoi_base(char *str, char *base)
{
	int base_size;
	int result;
	int sign;
	int i;

	base_size = parse_base(base);
	if (base_size == -1 || *str == 0)
		return (0);
	sign = (*str == '-') * -2 + 1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (*str != 0)
	{
		i = 0;
		while (i < base_size && *str != base[i])
			i++;
		if (i == base_size)
			return (0);
		result = result * base_size + i;
		str++;
	}
	return (result * sign);
}
