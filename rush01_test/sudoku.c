/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 09:09:35 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/21 11:00:29 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		my_putchar(char c)
{
	return (write(1, &c, 1));
}

int parse_board(char **args, int board[9][9])
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
	int i;
	char c;

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

void	display_possible(int possible[9][9][9])
{
	int x;
	int y;
	int i;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			i = 0;
			while (i < 9)
				if (possible[y][x][i])
					my_putchar('1' + i++);
				else
					i++;
			my_putchar('|');
			x++;
		}
		my_putchar('\n');
		y++;
	}
}

void	mark_impossible(int possible[9][9][9], int y, int x, int n)
{
	int ix;
	int iy;

	ix = 0;
	while (ix < 9)
		possible[y][ix++][n] = 0;
	iy = 0;
	while (iy < 9)
		possible[iy++][x][n] = 0;
	x = x / 3 * 3;
	y = y / 3 * 3;
	iy = 0;
	while (iy < 3)
	{
		ix = 0;
		while (ix < 3)
			possible[y + iy][x + ix++][n] = 0;
		iy++;
	}
}

int		possibilities_exist(int possible[9][9][9])
{
	int sum;
	int x;
	int y;
	int i;

	sum = 0;
	y = 0;
	while (y < 9)
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

int		get_possible(int possible[9])
{
	int i;
	int found;

	i = 0;
	found = 0;
	while (i < 9)
		if (possible[i] && found == 0)
			found = i++ + 1;
		else if (possible[i] && found != 0)
			return (0);
		else
			i++;
	return (found);
}

int		calculate_possible(int board[9][9], int possible[9][9][9])
{
	int i;
	int j;
	int found;

	i = 0;
	while (i < 9 * 9)
	{
		j = 0;
		if (board[i / 9][i % 9] != 0)
			while (j < 9)
				possible[i / 9][i % 9][j++] = 0;
		else
			while (j < 9)
				possible[i / 9][i % 9][j++] = 1;
		i++;
	}
	i = 0;
	while (i < 9 * 9)
	{
		if (board[i / 9][i % 9] != 0)
			mark_impossible(possible, i / 9, i % 9, board[i / 9][i % 9] - 1);
		i++;
	}
	while (possibilities_exist(possible))
	{
		display_possible(possible);
		i = 0;
		found = 0;
		while (i < 9 * 9)
		{
			if (get_possible(possible[i / 9][i % 9]) != 0)
			{
				board[i / 9][i % 9] = get_possible(possible[i / 9][i % 9]);
				mark_impossible(possible, i / 9, i % 9, board[i / 9][i % 9] - 1);
				found++;
				printf("%d,%d -> %d\n", i / 9, i % 9, board[i / 9][i % 9]);
			}
			i++;
		}
		if (found == 0)
			return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int board[9][9];
	int possible[9][9][9];
	if (argc < 10 || parse_board(argv + 1, board) != 0)
		write(1, "Error\n", 6);
	else
	{
		display_board(board);
		if (calculate_possible(board, possible))
			display_board(board);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
