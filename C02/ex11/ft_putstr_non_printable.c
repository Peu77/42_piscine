/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:58:41 by eebert            #+#    #+#             */
/*   Updated: 2024/08/04 13:22:22 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_char_printable(char c)
{
	return (c >= ' ' && c < 127);
}

void	ft_print_hex_decimal(int c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c > 16)
	{
		ft_print_hex_decimal(c / 10);
		ft_print_hex_decimal(c % 10);
	}
	else
		write(1, &hex[c], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (ft_is_char_printable(c))
		{
			write(1, &c, 1);
		}
		else
		{
			write(1, "\\", 1);
			if (str[i] < 16)
				write(1, "0", 1);
			ft_print_hex_decimal(c);
		}
		i++;
	}
}

// int	main(void)
// {
// 	char *c = "Coucou\ntu vas bien ?\1 \2 \3 \15";

// 	ft_putstr_non_printable(c);
// }