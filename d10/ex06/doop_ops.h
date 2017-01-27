/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop_ops.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:13:25 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/23 15:22:10 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_OPS_H
# define DOOP_OPS_H

typedef int(*t_op)(int, int);

int my_op_add(int a, int b);
int my_op_subtract(int a, int b);
int my_op_multiply(int a, int b);
int my_op_divide(int a, int b);
int my_op_modulo(int a, int b);

#endif
