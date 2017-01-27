/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:12:15 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/24 12:15:35 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *iter;
	t_list *next;

	iter = *begin_list;
	while (iter != 0)
	{
		next = iter->next;
		free(iter);
		iter = next;
	}
	*begin_list = 0;
}
