/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:52:24 by eebert            #+#    #+#             */
/*   Updated: 2024/08/08 21:46:21 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 10

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// void	print_board(int currentX, int board[SIZE])
// {
// 	int	y;
// 	int	x;

// 	if (!currentX)
// 		return ;
// 	y = SIZE - 1;
// 	while (y >= 0)
// 	{
// 		x = 0;
// 		while (x < SIZE)
// 		{
// 			if (board[x] == y)
// 			{
// 				printf("x");
// 			}
// 			else
// 			{
// 				printf("-");
// 			}
// 			x++;
// 		}
// 		printf("\n");
// 		y--;
// 	}
// }

// int	abs(int i)
// {
// 	if (i < 0)
// 		return (-i);
// 	return (i);
// }

void	print_solution(int board[SIZE])
{
	int		x;
	char	c2;

	x = 0;
	while (x < SIZE)
	{
		c2 = board[x] + '0';
		write(1, &c2, 1);
		x++;
	}
	write(1, "\n", 1);
}

int	is_valid_board(int x, int board[SIZE])
{
	int	i;
	int	y_diff;
	int	x_diff;

	i = 0;
	while (i < x)
	{
		y_diff = board[x] - board[i];
		x_diff = x - i;
		if (y_diff < 0)
			y_diff *= -1;
		if (x_diff < 0)
			x_diff *= -1;
		if (board[i] == board[x] || (x_diff == y_diff))
			return (0);
		i++;
	}
	return (1);
}

void	reset_board_at(int start_x, int *board)
{
	while (start_x < SIZE)
	{
		board[start_x] = 0;
		start_x++;
	}
}

int	solve(int x, int increase, int board[SIZE])
{
	int	y;

	if (x == SIZE || x < 0)
		return (1);
	y = board[x];
	if (increase)
		y++;
	reset_board_at(x, board);
	while (y < SIZE)
	{
		board[x] = y;
		if (is_valid_board(x, board))
		{
			if (x == SIZE - 1)
			{
				print_solution(board);
				return (solve(x - 1, 1, board) + 1);
			}
			return (solve(x + 1, 0, board));
		}
		y++;
	}
	return (solve(x - 1, 1, board));
}

int	ft_ten_queens_puzzle(void)
{
	int	board[SIZE];

	reset_board_at(0, board);
	return ((solve(0, 0, board)) - 1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_ten_queens_puzzle());
// }
