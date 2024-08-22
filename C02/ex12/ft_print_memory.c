/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:23:40 by eebert            #+#    #+#             */
/*   Updated: 2024/08/03 22:25:40 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_hex(char nb)
{
	char	buffer[16];
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		buffer[i] = 0;
		i++;
	}
	i = 0;
	while (nb > 0)
	{
		buffer[i] = hex[nb % 16];
		nb /= 16;
		i++;
	}
	while (i >= 0)
	{
		write(1, &buffer[i], 1);
		i--;
	}
}

void	print_char(char c)
{
	if (c < 16)
		write(1, "0", 1);
	write_hex(c);
}

// int	main(void)
// {
// 	int i = 6;
// 	int *p = &i;
// 	unsigned long number = (unsigned long)p;
// 	printf("%p\n", p);

// 	write(1, ": ", 2);

// 	for (int j = 0; j < 16; j += 2)
// 	{
// 		print_char(((char *)p)[j]);
// 		print_char(((char *)p)[j + 1]);
// 		write(1, " ", 1);
// 	}
// }