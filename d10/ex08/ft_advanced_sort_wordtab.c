/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:30:38 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/23 15:18:27 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	my_insertion_sort(char **tab, int (*cmp)(char*, char*))
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
		while (search < iter && cmp(*search, swap) <= 0)
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

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char*, char*))
{
	return (my_insertion_sort(tab, cmp));
}
