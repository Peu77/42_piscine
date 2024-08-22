/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:50:03 by eebert            #+#    #+#             */
/*   Updated: 2024/08/14 14:06:39 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_invalid_base(char *str);

int	power(int base, int power)
{
	int	nb;
	int	i;

	i = 0;
	nb = 1;
	while (i < power)
	{
		nb *= base;
		i++;
	}
	return (nb);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(long nbr, char *base, char *buffer, int *write_index)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		buffer[*write_index] = '-';
		*write_index += 1;
		nbr = -nbr;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base, buffer, write_index);
		ft_putnbr_base(nbr % base_len, base, buffer, write_index);
		return ;
	}
	buffer[*write_index] = base[nbr];
	*write_index += 1;
}

int	*create_0_int_pointer(void)
{
	int	*i;

	i = malloc(sizeof(int));
	return (i);
}

void	clear_buffer(char *buffer, int size)
{
	while (size >= 0)
	{
		buffer[size] = 0;
		size--;
	}
}
