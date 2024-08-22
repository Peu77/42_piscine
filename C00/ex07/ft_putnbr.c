/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:13:59 by eebert            #+#    #+#             */
/*   Updated: 2024/08/02 10:40:58 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_INT_STRING_LEN 10

void	print_digits(char *digits, int start)
{
	while (start >= 0)
	{
		if (digits[start])
			write(1, &digits[start], 1);
		start--;
	}
}

void	clean_array(char *list)
{
	int	i;

	i = 0;
	while (i < MAX_INT_STRING_LEN)
	{
		list[i] = 0;
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	buffer[MAX_INT_STRING_LEN];
	int		length;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	clean_array(buffer);
	length = 0;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (nb > 0)
	{
		buffer[length] = nb % 10 + '0';
		nb /= 10;
		length++;
	}
	print_digits(buffer, length - 1);
}

// int	main(void)
// {
// 	ft_putnbr(2147483646);
// 	write(1, "\n", 1);
// 	ft_putnbr(1234);
// 	write(1, "\n", 1);
// 	ft_putnbr(-4343);
// 	return (0);
// }
