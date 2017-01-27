/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:52:44 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/18 21:17:52 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

void		my_putstr(char *str)
{
	while (*str != 0)
		ft_putchar(*str++);
}

int			my_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 || *s2 != 0)
		if (*s1 != *s2)
			return (*s1 - *s2);
		else
		{
			s1++;
			s2++;
		}
	return (0);
}

void		my_insertion_sort_strings(char **strings, int length)
{
	int		i;
	int		k;
	char	*swap;

	i = 0;
	while (i < length)
	{
		k = i + 1;
		while (k < length)
		{
			if (my_strcmp(strings[i], strings[k]) > 0)
			{
				swap = strings[i];
				strings[i] = strings[k];
				strings[k] = swap;
			}
			k++;
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	int i;

	my_insertion_sort_strings(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		my_putstr(argv[i++]);
		ft_putchar('\n');
	}
	return (0);
}
