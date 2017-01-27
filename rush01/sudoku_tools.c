/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:57:55 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/22 20:23:53 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku_tools.h"

int		parse_board(char **args, int board[9][9])
{
	int i;

	i = 0;
	while (i < 9 * 9)
	{
		if (args[i / 9][i % 9] >= '0' && args[i / 9][i % 9] <= '9')
			board[i / 9][i % 9] = args[i / 9][i % 9] - '0';
		else if (args[i / 9][i % 9] == '.')
			board[i / 9][i % 9] = 0;
		else
			return (1);
		i++;
	}
	return (0);
}

void	display_board(int board[9][9])
{
	int		i;
	char	c;

	i = 0;
	while (i < 81)
	{
		c = board[i / 9][i % 9] + '0';
		if (c != '0')
			write(1, &c, 1);
		else
			write(1, ".", 1);
		write(1, " ", 1);
		if (i % 9 == 8)
			write(1, "\n", 1);
		i++;
	}
}

int		is_complete(int board[9][9])
{
	int i;

	i = 0;
	while (i < 9 * 9)
		if (board[i / 9][i % 9] == 0)
			return (0);
		else
			i++;
	return (1);
}

void	init_possible(int board[9][9], int possible[3][9][9])
{
	int i;

	i = 0;
	while (i < 9 * 9)
	{
		possible[0][i / 9][i % 9] = 1;
		possible[1][i / 9][i % 9] = 1;
		possible[2][i / 9][i % 9] = 1;
		i++;
	}
	i = 0;
	while (i < 9 * 9)
	{
		if (board[i / 9][i % 9] != 0)
			mark_impossible(possible, i / 9, i % 9, board[i / 9][i % 9] - 1);
		i++;
	}
}
