/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:58:59 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/24 13:16:58 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list *list;
	t_list *link;

	list = 0;
	if (ac > 0)
	{
		av++;
		while (*av != 0)
		{
			link = ft_create_elem(*av++);
			link->next = list;
			list = link;
		}
	}
	return (list);
}
