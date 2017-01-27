/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:04:12 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/14 15:59:49 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		recurse_queens(int row, int *hstate, int *dstate, int *rdstate)
{
	int taken[8];
	int i;
	int result;

	result = 0;
	i = -1;
	while (++i < 8)
		taken[i] = hstate[i] | dstate[i - row] | rdstate[i + row];
	i = -1;
	while (++i < 8)
		if (taken[i] == 0 && row == 7)
			result++;
		else if (taken[i] == 0)
		{
			hstate[i] = 1 + row;
			dstate[i - row] = 1 + row;
			rdstate[i + row] = 1 + row;
			result += recurse_queens(row + 1, hstate, dstate, rdstate);
			hstate[i] = 0;
			dstate[i - row] = 0;
			rdstate[i + row] = 0;
		}
	return (result);
}

int		ft_eight_queens_puzzle(void)
{
	int hstate[8];
	int dstate[16];
	int rdstate[16];
	int i;

	i = 0;
	while (i < 16)
	{
		hstate[i % 8] = 0;
		dstate[i] = 0;
		rdstate[i] = 0;
		i++;
	}
	return (recurse_queens(0, hstate, dstate + 8, rdstate));
}
