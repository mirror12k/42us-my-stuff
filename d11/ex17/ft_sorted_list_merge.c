/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:12:05 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/24 17:33:01 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, t_list *item, int (*cmp)())
{
	t_list *prev;
	t_list *iter;

	prev = 0;
	iter = *begin_list;
	while (iter != 0 && cmp(iter->data, item->data) <= 0)
	{
		prev = iter;
		iter = iter->next;
	}
	if (prev == 0)
	{
		*begin_list = item;
		(*begin_list)->next = iter;
	}
	else
	{
		prev->next = item;
		prev->next->next = iter;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list *iter;
	t_list *next;

	iter = begin_list2;
	while (iter != 0)
	{
		next = iter->next;
		ft_sorted_list_insert(begin_list1, iter, cmp);
		iter = next;
	}
}
