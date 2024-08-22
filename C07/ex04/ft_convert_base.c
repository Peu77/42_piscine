/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:00:36 by eebert            #+#    #+#             */
/*   Updated: 2024/08/14 18:59:50 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		power(int base, int power);
int		ft_strlen(char *str);
void	ft_putnbr_base(long nbr, char *base, char *buffer, int *write_index);
int		*create_0_int_pointer(void);
void	clear_buffer(char *buffer, int size);

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

int	is_invalid_base(char *str)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	if (len <= 1)
		return (1);
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		base_len;
	int		nb_len;
	int		nb_copy;
	char	*buffer;

	if (is_invalid_base(base_from) || is_invalid_base(base_to))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	nb_copy = nb;
	base_len = ft_strlen(base_to);
	nb_len = 0;
	while (nb_copy > 0)
	{
		nb_len++;
		nb_copy /= base_len;
	}
	buffer = malloc((nb_len + 1) * sizeof(char));
	clear_buffer(buffer, nb_len);
	ft_putnbr_base(nb, base_to, buffer, create_0_int_pointer());
	return (buffer);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_convert_base("11111011", "01", "0123456789ABCDEF"));
// }
