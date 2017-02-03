/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damn_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:31:34 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/02/01 14:08:43 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAMN_UTIL_H
# define DAMN_UTIL_H

char			*my_realloc(char *data, int size, int new_size);
int				index_of_free(char *s, char c, int n);
int				my_atoi(char *s);

#endif
