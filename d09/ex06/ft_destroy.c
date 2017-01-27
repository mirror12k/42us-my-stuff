/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 08:28:34 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/20 08:40:45 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	char ***factory_store;
	char **iter;

	factory_store = factory;
	while (*factory != NULL)
	{
		iter = *factory;
		while (*iter != NULL)
			free(*iter++);
		free(*factory++);
	}
	free(factory_store);
}
