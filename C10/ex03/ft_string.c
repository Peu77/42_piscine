/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:52:21 by eebert            #+#    #+#             */
/*   Updated: 2024/08/22 20:24:04 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_hex(unsigned char c)
{
	const char	*g_hex = "0123456789abcdef";

	write(1, g_hex + c / 16, 1);
	write(1, g_hex + c % 16, 1);
}

void	print_addr(int i, int len)
{
	const char	*g_hex = "0123456789abcdef";
	char		addr[8];
	int			j;

	j = 0;
	while (j < len)
	{
		addr[j] = g_hex[(i >> (4 * (len - 1 - j))) % 16];
		j++;
	}
	write(1, addr, len);
}
