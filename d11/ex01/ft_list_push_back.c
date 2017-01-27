/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:26:47 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/24 13:16:42 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *iter;

	if (*begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
	{
		iter = *begin_list;
		while (iter->next != 0)
			iter = iter->next;
		iter->next = ft_create_elem(data);
	}
}
