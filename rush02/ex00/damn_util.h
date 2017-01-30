/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damn_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:47:06 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/28 15:54:44 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAMN_UTIL_H
# define DAMN_UTIL_H

typedef struct	s_dim {
	int width;
	int height;
}				t_dim;

enum			e_rush_trace {
	RUSH_TOP_LEFT = 0,
	RUSH_TOP_RIGHT = 1,
	RUSH_BOTTOM_LEFT = 2,
	RUSH_BOTTOM_RIGHT = 3,
	RUSH_TOP_BOTTOM = 4,
	RUSH_LEFT_RIGHT = 5,
	RUSH_CENTER = 6,
};

char			*my_realloc(char *buffer, unsigned int size,
		unsigned int new_size);
char			*get_input(void);
int				my_strlen(char *str);
void			my_putnbr(int n);
void			print_trace(char *trace_name, t_dim dim, int first);

#endif
