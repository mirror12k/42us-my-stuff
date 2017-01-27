/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:40:27 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/24 16:55:03 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		my_list_length(t_list *list)
{
	int len;

	len = 0;
	while (list != 0)
	{
		list = list->next;
		len++;
	}
	return (len);
}

t_list	*my_list_forward(t_list *list, int pos)
{
	while (pos-- > 0)
		list = list->next;
	return (list);
}

void	my_swap(t_list *l1, t_list *l2)
{
	void *swap;

	swap = l1->data;
	l1->data = l2->data;
	l2->data = swap;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int len;
	int i;

	len = my_list_length(begin_list);
	i = 0;
	while (i < len / 2)
	{
		my_swap(
				my_list_forward(begin_list, i),
				my_list_forward(begin_list, len - i - 1));
		i++;
	}
}
