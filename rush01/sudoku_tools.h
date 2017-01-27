/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:03:07 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/22 20:30:55 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_TOOLS_H
# define SUDOKU_TOOLS_H

# include "sudoku_more.h"

int		parse_board(char **args, int board[9][9]);
void	display_board(int board[9][9]);
int		is_complete(int board[9][9]);
void	init_possible(int board[9][9], int possible[3][9][9]);

#endif
