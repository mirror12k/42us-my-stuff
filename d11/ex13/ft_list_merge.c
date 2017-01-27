/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:08:44 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/24 15:11:56 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *iter;

	if (*begin_list1 == 0)
		*begin_list1 = begin_list2;
	else
	{
		iter = *begin_list1;
		while (iter->next != 0)
			iter = iter->next;
		iter->next = begin_list2;
	}
}
