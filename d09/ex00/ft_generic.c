/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:18:07 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/19 18:35:41 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_generic(void)
{
	char *text;

	text = "Tu tu tu tu ; Tu tu tu tu\n";
	write(1, text, sizeof("Tu tu tu tu ; Tu tu tu tu\n"));
}
