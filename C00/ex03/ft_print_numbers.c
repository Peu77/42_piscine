/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:14:58 by eebert            #+#    #+#             */
/*   Updated: 2024/08/01 12:33:27 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	current_char;

	current_char = '0';
	while (current_char <= '9')
	{
		write(1, &current_char, 1);
		current_char++;
	}
}

// int	main(void)
// {
// 	ft_print_numbers();
// }
