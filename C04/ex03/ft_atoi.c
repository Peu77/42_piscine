/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:28:25 by eebert            #+#    #+#             */
/*   Updated: 2024/08/10 20:51:43 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == ' ' || c == '\r' || c == '\f' || c == '\v' || c == '\n'
		|| c == '\t');
}

int	ft_atoi(char *str)
{
	int				nb;
	unsigned int	minus_count;

	nb = 0;
	minus_count = 0;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = *str - '0' + (nb * 10);
		str++;
	}
	if (minus_count % 2 != 0)
		return (-nb);
	return (nb);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*str;
// 	int		i;
// 	int		result;
// 	int		result2;

// 	str = "  \r \f  \t\n \v  \n  -2147483648-7";
// 	result = ft_atoi(str);
// 	result2 = atoi(str);
// 	printf("result: %d result2: %d", result, result2);
// }
