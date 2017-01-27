/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:47:20 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/23 15:15:42 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != 0)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	my_insertion_sort(char **tab)
{
	char *swap;
	char *swap2;
	char **iter;
	char **search;

	iter = tab;
	while (*iter != 0)
	{
		swap = *iter;
		search = tab;
		while (search < iter && my_strcmp(*search, swap) <= 0)
			search++;
		while (search < iter)
		{
			swap2 = *search;
			*search = swap;
			swap = swap2;
			search++;
		}
		*iter = swap;
		iter++;
	}
}

void	ft_sort_wordtab(char **tab)
{
	my_insertion_sort(tab);
}
