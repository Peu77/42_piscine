/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:38:09 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 13:19:40 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int number)
{
	char	a;
	char	b;

	a = number / 10 + '0';
	b = number % 10 + '0';
	write(1, &a, 1);
	write(1, &b, 1);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			print_number(x);
			write(1, " ", 1);
			print_number(y);
			if (x != 98)
				write(1, ", ", 2);
			y++;
		}
		x++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// }
