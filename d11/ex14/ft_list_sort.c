/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:38:14 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/24 16:14:20 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*select_largest(t_list **list, int (*cmp)())
{
	t_list *iter;
	t_list *pre_largest;
	t_list *largest;

	iter = *list;
	pre_largest = 0;
	largest = iter;
	while (iter->next != 0)
	{
		if (cmp(largest->data, iter->next->data) < 0)
		{
			largest = iter->next;
			pre_largest = iter;
		}
		iter = iter->next;
	}
	if (pre_largest)
		pre_largest->next = largest->next;
	else
		*list = largest->next;
	return (largest);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *built;
	t_list *link;

	built = 0;
	while (*begin_list)
	{
		link = select_largest(begin_list, cmp);
		link->next = built;
		built = link;
	}
	*begin_list = built;
}
