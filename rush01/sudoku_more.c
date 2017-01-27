/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 09:09:35 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/22 20:31:11 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "sudoku_more.h"

void	mark_impossible(int possible[3][9][9], int y, int x, int n)
{
	possible[0][y][n] = 0;
	possible[1][x][n] = 0;
	possible[2][y / 3 * 3 + x / 3][n] = 0;
}

int		get_possible(int possible[3][9][9], int y, int x)
{
	int i;
	int found;

	found = 0;
	i = 0;
	while (i < 9)
	{
		if (possible[0][y][i] && possible[1][x][i]
				&& possible[2][y / 3 * 3 + x / 3][i])
		{
			if (found == 0)
				found = i++ + 1;
			else
				return (0);
		}
		else
			i++;
	}
	return (found);
}

int		possibilities_exist(int possible[3][9][9])
{
	int sum;
	int x;
	int y;
	int i;

	sum = 0;
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 9)
		{
			i = 0;
			while (i < 9)
				sum += possible[y][x][i++];
			x++;
		}
		y++;
	}
	return (sum);
}

int		calculate_possible(int board[9][9], int possible[3][9][9])
{
	int i;
	int found;

	while (possibilities_exist(possible))
	{
		i = 0;
		found = 0;
		while (i < 9 * 9)
		{
			if (board[i / 9][i % 9] == 0 &&
					get_possible(possible, i / 9, i % 9) != 0)
			{
				board[i / 9][i % 9] = get_possible(possible, i / 9, i % 9);
				mark_impossible(possible, i / 9, i % 9,
						board[i / 9][i % 9] - 1);
				found++;
			}
			i++;
		}
		if (found == 0)
			return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int board[9][9];
	int possible[3][9][9];

	if (argc < 10 || parse_board(argv + 1, board) != 0)
		write(1, "Error\n", 6);
	else
	{
		init_possible(board, possible);
		if (!calculate_possible(board, possible))
			write(1, "Error\n", 6);
		else if (is_complete(board))
			display_board(board);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
