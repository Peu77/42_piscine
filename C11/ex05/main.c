/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:56:53 by eebert            #+#    #+#             */
/*   Updated: 2024/08/19 15:12:47 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	is_valid_operator(char *operator)
{
	if (operator[1] != 0)
		return (0);
	return (operator[0] == '+' || operator[0] == '-' || operator[0] == '/'
		|| operator[0] == '%' || operator[0] == '*');
}

void	ft_putnbr(int nb);

void	do_operation(char operator, int a, int b)
{
	int	result;

	if (operator == '+')
		result = a + b;
	if (operator == '-')
		result = a - b;
	if (operator == '/')
		result = a / b;
	if (operator == '%')
		result = a % b;
	if (operator == '*')
		result = a * b;
	ft_putnbr(result);
	write(1, "\n", 1);
}

int	main(int argc, char **args)
{
	int	a;
	int	b;

	if (argc != 4)
		return (1);
	if (!is_valid_operator(args[2]))
	{
		write(1, "0\n", 2);
		return (1);
	}
	a = ft_atoi(args[1]);
	b = ft_atoi(args[3]);
	if (args[2][0] == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	if (args[2][0] == '/' && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	do_operation(args[2][0], a, b);
	return (0);
}
