/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 09:09:35 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/22 16:50:48 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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

int		get_possible(int board[9][9], int possible[3][9][9], int y, int x)
{
	int i;
	int found;

	found = 0;
	i = 0;
	if (board[y][x] != 0)
		return (0);
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

int		mark_impossible(int possible[3][9][9], int i, int n, int v)
{
	possible[0][i / 9][n] = v;
	possible[1][i % 9][n] = v;
	possible[2][(i / 9) / 3 * 3 + (i % 9) / 3][n] = v;
	return (1);
}

int		calculate_possible(int board[9][9], int possible[3][9][9])
{
	int i;
	int miss;
	int found;

	i = -1;
	while (++i < 9 * 9 * 9)
		mark_impossible(possible, i % 81, i / 81, 1);
	i = -1;
	while (++i < 9 * 9)
		if (board[i / 9][i % 9] != 0)
			mark_impossible(possible, i, board[i / 9][i % 9] - 1, 0);
	found = 1;
	while (found > 0)
	{
		i = -1;
		miss = 0;
		found = 0;
		while (++i < 9 * 9)
			if (get_possible(board, possible, i / 9, i % 9) != 0)
				found += mark_impossible(possible, i, (board[i / 9][i % 9] =
						get_possible(board, possible, i / 9, i % 9)) - 1, 0);
			else
				miss += board[i / 9][i % 9] == 0;
	}
	return (miss);
}

int		main(int argc, char **argv)
{
	int i;
	int board[9][9];
	int possible[3][9][9];

	if (argc < 10)
		return (write(1, "Error\n", 6));
	i = -1;
	while (++i < 9 * 9)
		if (argv[1 + i / 9][i % 9] >= '0' && argv[1 + i / 9][i % 9] <= '9')
			board[i / 9][i % 9] = argv[1 + i / 9][i % 9] - '0';
		else if (argv[1 + i / 9][i % 9] == '.')
			board[i / 9][i % 9] = 0;
		else
			return (write(1, "Error\n", 6));
	if (!calculate_possible(board, possible))
		display_board(board);
	else
		write(1, "Error\n", 6);
	return (0);
}
