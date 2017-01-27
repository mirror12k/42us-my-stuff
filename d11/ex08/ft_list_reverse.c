/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:34:20 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/24 13:17:40 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *iter;
	t_list *next;
	t_list *next_next;

	if (*begin_list != 0)
	{
		iter = *begin_list;
		next = iter->next;
		while (next != 0)
		{
			next_next = next->next;
			next->next = iter;
			iter = next;
			next = next_next;
		}
		(*begin_list)->next = 0;
		*begin_list = iter;
	}
}
