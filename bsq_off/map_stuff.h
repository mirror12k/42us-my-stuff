/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:24:08 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/02/01 14:00:46 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_STUFF_H
# define MAP_STUFF_H

typedef struct	s_map_descriptor {
	int			w;
	int			h;
	char		c_empty;
	char		c_obstacle;
	char		c_full;
	char		*data;
}				t_map;
typedef struct	s_square {
	int			w;
	int			x;
	int			y;
}				t_square;

t_map			parse_legend(char *data, int size);
int				is_valid_map(t_map map);
t_square		parse_bsq(t_map map);
void			mark_box(t_map map, t_square box);

#endif
