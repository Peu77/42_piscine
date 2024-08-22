/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:05:01 by eebert            #+#    #+#             */
/*   Updated: 2024/08/10 20:51:49 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	contains_invalid_chars(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == '+' || str[i] == '-')
				return (1);
			if (str[i] == str[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	char_to_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	sum_digits(char *str, char *base, int base_len)
{
	int	nb;
	int	base_index;
	int	number_len;
	int	i;

	nb = 0;
	number_len = 0;
	i = 0;
	while (char_to_base_index(str[number_len], base) != -1)
		number_len++;
	while (str[i])
	{
		base_index = char_to_base_index(str[i], base);
		if (base_index == -1)
			break ;
		nb += base_index * power(base_len, number_len - 1 - i);
		i++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	minus_count;
	int	base_len;

	base_len = 0;
	nb = 0;
	minus_count = 0;
	while (base[base_len])
		base_len++;
	if (contains_invalid_chars(base) || base_len <= 1)
		return (0);
	while ((*str == ' ' || *str == '\r' || *str == '\f' || *str == '\v'
			|| *str == '\n' || *str == '\t'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_count++;
		str++;
	}
	nb = sum_digits(str, base, base_len);
	if (minus_count % 2 != 0)
		return (-nb);
	return (nb);
}

// #include <stdlib.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
// 	printf("%d\n", atoi("432423"));
// }