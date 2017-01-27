/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_more.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:03:19 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/22 20:30:48 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_MORE_H
# define SUDOKU_MORE_H

# include "sudoku_tools.h"

void	mark_impossible(int possible[3][9][9], int y, int x, int n);
int		get_possible(int possible[3][9][9], int y, int x);
int		possibilities_exist(int possible[3][9][9]);
int		calculate_possible(int board[9][9], int possible[3][9][9]);
int		main(int argc, char **argv);

#endif
