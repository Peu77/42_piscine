/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:11:48 by eebert            #+#    #+#             */
/*   Updated: 2024/08/02 11:36:38 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_N_SIZE 9

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_able_to_print(int *numbers, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (numbers[i] >= numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_numbers(int *numbers, int n)
{
	int	i;

	if (!is_able_to_print(numbers, n))
		return ;
	i = 1;
	i = 0;
	while (i < n)
		ft_putchar(numbers[i++] + '0');
	if (numbers[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	numbers[MAX_N_SIZE];
	int	i;

	i = 0;
	while (i < n)
		numbers[i++] = 0;
	while (numbers[0] <= (10 - n))
	{
		print_numbers(numbers, n);
		numbers[n - 1]++;
		i = n - 1;
		while (i)
		{
			if (numbers[i] > 9)
			{
				numbers[i - 1]++;
				numbers[i] = 0;
			}
			i--;
		}
	}
}

// int	main(void)
// {
// 	ft_print_combn(3);
// }
