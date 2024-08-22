/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:43:21 by eebert            #+#    #+#             */
/*   Updated: 2024/08/10 20:54:14 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	contains_invalid_chars(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (str[i] == '+' || str[i] == '-')
				return (1);
			if (str[i] == str[j] && i != j)
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(long nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (base_len == 0 || base_len == 1)
		return ;
	if (contains_invalid_chars(base, base_len))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base);
		ft_putnbr_base(nbr % base_len, base);
		return ;
	}
	write(1, &base[nbr], 1);
}

// int	main(void)
// {
// 	int	nbr;

// 	nbr = -2147483648;
// 	ft_putnbr_base(nbr, "0123456789");
// 	ft_putnbr_base(nbr, "0123456789ABCDEF");
// 	ft_putnbr_base(nbr, "01");
// 	ft_putnbr_base(nbr, "abcdef");
// }
