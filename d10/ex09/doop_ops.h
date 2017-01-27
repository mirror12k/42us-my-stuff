/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop_ops.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:13:25 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/23 14:52:16 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_OPS_H
# define DOOP_OPS_H

typedef int(*t_op)(int, int);

struct		s_opp {
	char	*key;
	t_op	fun;
};

typedef struct s_opp	t_opp;

int			ft_add(int a, int b);
int			ft_sub(int a, int b);
int			ft_mul(int a, int b);
int			ft_div(int a, int b);
int			ft_mod(int a, int b);
int			ft_usage(int a, int b);

#endif
