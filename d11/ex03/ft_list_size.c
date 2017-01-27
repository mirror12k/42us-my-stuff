/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:43:03 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/24 11:47:49 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int len;

	len = 0;
	while (begin_list != 0)
	{
		begin_list = begin_list->next;
		len++;
	}
	return (len);
}
