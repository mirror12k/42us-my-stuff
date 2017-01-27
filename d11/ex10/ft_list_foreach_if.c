/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:19:36 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/24 13:27:07 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void*),
		void *data_ref, int (*cmp)())
{
	t_list *iter;

	iter = begin_list;
	while (iter != 0)
	{
		if (cmp(iter->data, data_ref) == 0)
			f(iter->data);
		iter = iter->next;
	}
}
